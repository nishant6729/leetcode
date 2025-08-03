class Solution {
public:
    int dp[101][101];
    int helper(int i,int j,int m,int n){
        if(dp[i][j]!=-1) return dp[i][j];
        if(i==m-1 && j==n-1) return 1;
        if(i>=m || j>=n) return 0;
        int down=helper(i+1,j,m,n);
        int right=helper(i,j+1,m,n);
        return dp[i][j]=(down+right);
    }
    int uniquePaths(int m, int n) {
        memset(dp,-1,sizeof(dp));
        int ans=helper(0,0,m,n);
        return ans;
    }
};