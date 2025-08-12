class Solution {
public:
    vector<int> v;
    int dp[5001][2];
    int helper(int idx,int purchase){
        if(idx>=v.size()) return 0;
        if(dp[idx][purchase]!=-1) return dp[idx][purchase];
        if(purchase==1){
            //purchase kiya
            int taken=helper(idx+1,0)-v[idx];
            int not_taken=helper(idx+1,1);
            return dp[idx][purchase]=max(taken,not_taken);
        }
        else{
            int sold=v[idx]+helper(idx+2,1);
            int not_sold=helper(idx+1,0);
            return dp[idx][purchase]=max(sold,not_sold);
        }
        
    }
    int maxProfit(vector<int>& prices) {
        v=prices;
        memset(dp,-1,sizeof(dp));
        int ans=helper(0,1);
        return ans;
    }
};