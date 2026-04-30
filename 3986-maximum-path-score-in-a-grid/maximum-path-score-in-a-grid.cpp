class Solution {
public:
    int m,n;
    
    int helper(int i,int j,vector<vector<int>>& grid, int k,vector<vector<vector<int>>>& dp){
        if(i>=m || j>=n) return INT_MIN;
        int cost;

        int score=grid[i][j];
        
        if(grid[i][j]==0){
            cost=0;
        }
        else{
            cost=1;

        }
        
        if(cost>k){
            return INT_MIN;
        }

        if(i==m-1 && j==n-1){
            return grid[i][j];
        }

        if(dp[i][j][k]!=-1) return dp[i][j][k];

        int case1=helper(i+1,j,grid,k-cost,dp);

        int case2=helper(i,j+1,grid,k-cost,dp);


        if(case1!=INT_MIN){
            case1+=grid[i][j];
        }
        if(case2!=INT_MIN){
            case2+=grid[i][j];
        }

        return dp[i][j][k]=max(case1,case2);
    }
    int maxPathScore(vector<vector<int>>& grid, int k) {

        m=grid.size();
        n=grid[0].size();

        k=min(k,m+n);


        vector<vector<vector<int>>> dp(m+1,vector<vector<int>>(n+1,vector<int>(k+1,-1)));
       

        int ans=helper(0,0,grid,k,dp);

        if(ans==INT_MIN) return -1;

        return ans;
    }
};