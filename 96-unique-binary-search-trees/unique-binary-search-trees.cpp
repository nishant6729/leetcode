class Solution {
public:
    int f(vector<int> &dp,int n){
        if(n==0) return dp[n]=1;
        if(n==1) return dp[n]=1;
        if(n==2) return dp[n]=2;
        if(dp[n]!=-1) return dp[n];
        int sum=0;
        for(int k=1;k<=n;k++){
            // make k as root node step wise
            sum+=f(dp,k-1)*f(dp,n-k);
        }
        return dp[n]=sum;
    }
    int numTrees(int n) {
        vector<int> dp(400,-1);
        return f(dp,n);
    }
};