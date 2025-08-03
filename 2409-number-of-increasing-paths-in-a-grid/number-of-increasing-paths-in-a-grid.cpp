class Solution {
public:
    int m,n;
    long long dp[1001][1001];
    long long helper(vector<vector<int>>& matrix,int i,int j){
        long long up=0;
        long long down=0;
        long long left=0;
        long long right=0;
        if(dp[i][j]!=-1) return dp[i][j];
        if (i+1 < m && matrix[i+1][j] > matrix[i][j]) 
            down  = 1LL * helper(matrix, i+1, j);
        if (j+1 < n && matrix[i][j+1] > matrix[i][j]) 
            right = 1LL * helper(matrix, i, j+1);
        if (i-1 >= 0 && matrix[i-1][j] > matrix[i][j]) 
            up    = 1LL * helper(matrix, i-1, j);
        if (j-1 >= 0 && matrix[i][j-1] > matrix[i][j]) 
            left  = 1LL * helper(matrix, i, j-1);
        long long temp=(1+down+left+right+up)%(1000000007);
        return dp[i][j]=temp;
    }
    int countPaths(vector<vector<int>>& grid) {
        memset(dp,-1,sizeof(dp));
        m=grid.size();
        n=grid[0].size();
        long long ans=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                ans = (ans + helper(grid, i, j)) % 1'000'000'007;;
            }
        }
        return (int)ans;
    }
};