class Solution {
public:
    int dp[51][51];
    int helper(vector<int>& values,int i,int j){
        if(j-i==1){
            return 0;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        int ans=INT_MAX;
        for(int k=i+1;k<j;k++){
            ans=min(ans,helper(values,i,k)+(values[i]*values[j]*values[k])+helper(values,k,j));
        }
        return dp[i][j]=ans;
    }
    int minScoreTriangulation(vector<int>& values) {
        memset(dp,-1,sizeof(dp));
        int n=values.size();
        int ans=helper(values,0,n-1);
        return ans;
    }
};