class Solution {
public:
    int dp[51][51];
    int solve(vector<int>& v,int i,int j){
        if(i+1==j){
            return 0;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        int ans=INT_MAX;
        for(int k=i+1;k<j;k++){
            ans=min(ans,v[i]*v[j]*v[k]+solve(v,i,k)+solve(v,k,j));
        }
        return dp[i][j]=ans;
    }
    int minScoreTriangulation(vector<int>& v) {
        memset(dp,-1,sizeof(dp));
        int n=v.size();
        int ans=solve(v,0,n-1);
        return ans;
    }
};