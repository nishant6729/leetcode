class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int> mp;
        for(auto i:nums){
            mp[i]++;
        }
        if(mp[0]==0 || mp[0]==1) return n-1;

        int prev=0;
        int next=0;
        priority_queue<int> pq;
        int i=0;
        while(i<n){
            while(i<n && nums[i]==1){
                prev++;
                i++;
            }
            i++;
            while(i<n && nums[i]==1){
                next++;
                i++;
            }
            pq.push(next+prev);
            prev=next;
            next=0;
        }
        return pq.top();
    }
};