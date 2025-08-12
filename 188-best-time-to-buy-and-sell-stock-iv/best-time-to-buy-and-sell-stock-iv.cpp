class Solution {
public:
    vector<int> v;
    int dp[1001][2][101];
    int helper(int idx,int purchase,int k){
        if(idx>=v.size()) return 0;
        if(k<=0) return 0;
        if(dp[idx][purchase][k]!=-1) return dp[idx][purchase][k];
        if(purchase==1){
            int taken=helper(idx+1,0,k)-v[idx];
            int not_taken=helper(idx+1,1,k);
            return dp[idx][purchase][k]=max(taken,not_taken);
        }
        else{
            int sold=helper(idx+1,1,k-1)+v[idx];
            int not_sold=helper(idx+1,0,k);
            return dp[idx][purchase][k]=max(sold,not_sold);
        }
    }
    int maxProfit(int k, vector<int>& prices) {
        v=prices;
        memset(dp,-1,sizeof(dp));
        int ans=helper(0,1,k);
        return ans;
    }
};