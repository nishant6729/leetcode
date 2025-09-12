class Solution {
public:
    vector<int> arr;
    int n;
    int dp[10001];
    int helper(int idx){
        if(idx==n-1) return 0;
        if(idx>=n){
            return INT_MAX;
        }
        if(dp[idx]!=-1) return dp[idx];
        int curr=arr[idx];

        if(curr==0) return INT_MAX;
        if(idx+curr>=n-1) return 1;
        int ans=INT_MAX;
        for(int i=1;i<=curr;i++){
            ans=min(ans,helper(idx+i));
        }
        if(ans==INT_MAX) return INT_MAX;
        return dp[idx]=1+ans;
    }
    int jump(vector<int>& nums) {
        arr=nums;
        n=nums.size();
        memset(dp,-1,sizeof(dp));
        return helper(0);
    }
};