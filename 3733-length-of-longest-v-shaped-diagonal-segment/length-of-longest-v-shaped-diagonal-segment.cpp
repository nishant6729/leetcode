class Solution {
public:
    vector<vector<int>> dir={{-1,-1},{-1,1},{1,-1},{1,1}};
    int m,n;
    int dp[501][501][5][2];
    vector<vector<int>> nums;
    int helper(int i,int j,int currDir,int allowed){
        if(i<0 || i>=m || j<0 || j>=n) return 0;
        int target;
        if(nums[i][j]==1) target=2;
        else if(nums[i][j]==2) target=0;
        else target=2;

        if(dp[i][j][currDir+1][allowed]!=-1) return dp[i][j][currDir+1][allowed];
        if(currDir==-1){
            int best=0;
            for(int k=0;k<4;k++){
                vector<int> d=dir[k];
                int nextI=i+d[0];
                int nextJ=j+d[1];
                
                if(((nextI>=0 && nextI<m) && (nextJ>=0 && nextJ<n)) && (nums[nextI][nextJ]==target)){
                    best=max(best,helper(nextI,nextJ,k,allowed));
                }
            }
            return dp[i][j][currDir+1][allowed]=1+best;
        }
        else{
            int nextI=i+dir[currDir][0];
            int nextJ=j+dir[currDir][1];
            int best=0;
            if(((nextI>=0 && nextI<m) && (nextJ>=0 && nextJ<n)) && (nums[nextI][nextJ]==target)){
                    best=max(best,helper(nextI,nextJ,currDir,allowed));
                    if(allowed==1){
                        int clockDir;
                        if(currDir==0) clockDir=1;
                        else if(currDir==1) clockDir=3;
                        else if(currDir==2) clockDir=0;
                        else clockDir=2;

                        int clockI=i+dir[clockDir][0];
                        int clockJ=j+dir[clockDir][1];

                        if(((clockI>=0 && clockI<m) && (clockJ>=0 && clockJ<n)) && (nums[clockI][clockJ]==target)){
                            best=max(best,helper(clockI,clockJ,clockDir,0));
                        }
                    }
                    return dp[i][j][currDir+1][allowed]=1+best;
            }
            else{
                if(allowed==0) return dp[i][j][currDir+1][allowed]=1;
                int clockDir;
                if(currDir==0) clockDir=1;
                else if(currDir==1) clockDir=3;
                else if(currDir==2) clockDir=0;
                else clockDir=2;

                int clockI=i+dir[clockDir][0];
                int clockJ=j+dir[clockDir][1];

                if(((clockI>=0 && clockI<m) && (clockJ>=0 && clockJ<n)) && (nums[clockI][clockJ]==target)){
                    return dp[i][j][currDir+1][allowed]=1+helper(clockI,clockJ,clockDir,0);
                }
                else return dp[i][j][currDir+1][allowed]=1;
            }
        }
        
    }
    int lenOfVDiagonal(vector<vector<int>>& grid) {
        memset(dp,-1,sizeof(dp));
        nums=grid;
        m=grid.size();
        n=grid[0].size();
        int ans=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    ans=max(ans,helper(i,j,-1,1));
                }
            }
        }
        return ans;
    }
};