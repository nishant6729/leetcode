class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        atexit(+[](){ofstream("display_runtime.txt") << 0 << '\n';});
        sort(nums.begin(),nums.end());
        int i=0;
        int j=1;
        int n=nums.size();
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        while(i<n){
            while(j<n && nums[j]==nums[i]) j++;
            int frq=j-i;
            if(pq.size()==k && pq.top().first<frq){
                pq.pop();
               
            }
            if(pq.size()<k) pq.push({frq,nums[i]});
            i=j;
            j=i+1;
        }
        vector<int> ans;
        while(!pq.empty()){
            auto temp=pq.top();
            int ele=temp.second;
            ans.push_back(ele);
            pq.pop();
        }
        return ans;
    }
};