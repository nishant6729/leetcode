class Solution {
public:
    int p;
    int dp[301][301];
    static const int MOD=1000000007;
    int helper(int n,int si){
        if(n==0) return 1;
        if(n<0) return 0;
        if(dp[n][si]!=-1) return dp[n][si];
        long long count=0;
        int last = (int)round(pow(n, 1.0/p)); // now 4
        for(int i=si+1;i<=last;i++){
            long long sub=pow(i,p);
            count+=helper(n-sub,i);
            if(count>=MOD) count%MOD;
        }
        return dp[n][si]=count%MOD;
    }
    int numberOfWays(int n, int x) {
        memset(dp,-1,sizeof(dp));
        p=x;
        int ans=helper(n,0);
        return ans;
    }
};