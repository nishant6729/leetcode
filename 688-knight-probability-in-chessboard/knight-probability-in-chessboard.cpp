class Solution {
public:
    int m;
    double dp[101][25][25];
    double helper(int k,int r,int j){
        if(k==0) return 1.0;
        double ans=0.0;
        if(dp[k][r][j]!=-1.0) return dp[k][r][j];
        if(r-2>=0 && j-1>=0){
            ans+=(1.0/8.0)*helper(k-1,r-2,j-1);
        }
        if(r-2>=0 && j+1<m){
            ans+=(1.0/8.0)*helper(k-1,r-2,j+1);
        }
        if(r-1>=0 && j-2>=0){
            ans+=(1.0/8.0)*helper(k-1,r-1,j-2);
        }
        if(r-1>=0 && j+2<m){
            ans+=(1.0/8.0)*helper(k-1,r-1,j+2);
        }
        if(r+1<m && j+2<m){
            ans+=(1.0/8.0)*helper(k-1,r+1,j+2);
        }
        if(r+1<m && j-2>=0){
            ans+=(1.0/8.0)*helper(k-1,r+1,j-2);
        }
        if(r+2<m && j+1<m){
            ans+=(1.0/8.0)*helper(k-1,r+2,j+1);
        }
        if(r+2<m && j-1>=0){
            ans+=(1.0/8.0)*helper(k-1,r+2,j-1);
        }
        return dp[k][r][j]=ans;
    }
    double knightProbability(int n, int k, int row, int column) {
        for(int i = 0; i <= k; ++i)
            for(int r = 0; r < n; ++r)
                for(int c = 0; c < n; ++c)
                    dp[i][r][c] = -1.0;
        m=n;
        double ans=helper(k,row,column);
        return ans;
    }
};