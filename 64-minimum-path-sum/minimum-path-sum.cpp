class Solution {
public:
    int m,n;
    int dp[201][201];
    int helper(vector<vector<int>>& grid,int i,int j){
        if(i>=m || j>=n) return INT_MAX;
        if(i==m-1 && j==n-1) return grid[i][j];
        if(dp[i][j]!=-1) return dp[i][j];
        int down=helper(grid,i+1,j);
        int right=helper(grid,i,j+1);
        return dp[i][j]=grid[i][j]+min(down,right);
    }
    int minPathSum(vector<vector<int>>& grid) {
        memset(dp,-1,sizeof(dp));
        m=grid.size();
        n=grid[0].size();
        int ans=helper(grid,0,0);
        return ans;
    }
};