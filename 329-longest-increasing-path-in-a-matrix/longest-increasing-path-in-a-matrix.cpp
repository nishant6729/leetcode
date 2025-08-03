class Solution {
public:
    int m,n;
    int dp[201][201];
    int helper(vector<vector<int>>& matrix,int i,int j){

        int down=0;
        int up=0;
        int right=0;
        int left=0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(i+1<m && matrix[i+1][j]>matrix[i][j]) down=helper(matrix,i+1,j);
        if(j+1<n && matrix[i][j+1]>matrix[i][j]) right=helper(matrix,i,j+1);
        if(i-1>=0 && matrix[i-1][j]>matrix[i][j]) up=helper(matrix,i-1,j);
        if(j-1>=0 && matrix[i][j-1]>matrix[i][j]) left=helper(matrix,i,j-1);
        return dp[i][j]=1+max({down,left,right,up});
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        memset(dp,-1,sizeof(dp));
        m=matrix.size();
        n=matrix[0].size();
        int ans=1;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                ans=max(ans,helper(matrix,i,j));
            }
        }
        return ans;
    }
};