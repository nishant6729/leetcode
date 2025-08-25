class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        int n=nums.size();
        if(n==1 || n==2){
            return accumulate(nums.begin(),nums.end(),0);
        }
        vector<int> dp(n,-1);

        dp[n-1]=nums[n-1];
        dp[n-2]=nums[n-2]+nums[n-1];


        priority_queue<pair<int,int>> pq;
        pq.push({nums[n-1],n-1});
        pq.push({dp[n-2],n-2});
        for(int i=n-3;i>=0;i--){
            while (!pq.empty() && pq.top().second > i + k) {
                pq.pop();
            }
            int req=pq.top().first;
            dp[i]=nums[i]+req;
            pq.push({dp[i],i});
        }
        return dp[0];
    }
};