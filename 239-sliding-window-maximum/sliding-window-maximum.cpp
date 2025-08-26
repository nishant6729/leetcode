class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<pair<int,int>> pq;
        vector<int> ans;
        for(int i=0;i<k-1;i++){
            pq.push({nums[i],i});
        }
        int i=0;
        int j=k-1;
        int n=nums.size();
        while(j<n){
            pq.push({nums[j],j});
            while(!pq.empty() && (pq.top().second < i || pq.top().second > j)) {
                pq.pop();
            }
            ans.push_back(pq.top().first);

            i++;
            j++;

        }
        return ans;
    }
};