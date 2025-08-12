class Solution {
public:
    vector<int> v;
    int dp[100001][2][3];
    int helper(int idx,int purchase,int rem){
        if(rem<=0) return 0;
        if(idx>=v.size()) return 0;
        if(dp[idx][purchase][rem]!=-1) return dp[idx][purchase][rem];
        if(purchase==1){
            int take=helper(idx+1,false,rem)-v[idx];
            int not_take=helper(idx+1,true,rem);
            return dp[idx][purchase][rem]=max(take,not_take);
        }
        else{
            int sold=helper(idx+1,true,rem-1)+v[idx];
            int not_sold=helper(idx+1,false,rem);
            return dp[idx][purchase][rem]=max(sold,not_sold);
        }
        
    }
    int maxProfit(vector<int>& prices) {
        v=prices;
        memset(dp,-1,sizeof(dp));
        int ans=helper(0,1,2);
        return ans;
    }
};