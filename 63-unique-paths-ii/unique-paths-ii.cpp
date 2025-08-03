class Solution {
public:
    int m,n;
    int dp[101][101];
    int helper(vector<vector<int>>& v,int i,int j){
        if(i==m-1 && j==n-1) return 1;
        if(i>=m || j>=n || v[i][j]) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int down=helper(v,i+1,j);
        int right=helper(v,i,j+1);
        return dp[i][j]=(down+right);
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        
        memset(dp,-1,sizeof(dp));
        m=obstacleGrid.size();
        n=obstacleGrid[0].size();
        if(obstacleGrid[m-1][n-1]==1) return 0;
        int ans=helper(obstacleGrid,0,0);
        return ans;
    }
};