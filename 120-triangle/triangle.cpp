class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        //Pta nhi kya hua hai Recursion + Memo pass nhi ho rha pehle submit ho rha tha
        // Lets see Bottom Up code
        int n=triangle.size();
        vector<vector<int>> dp(n,vector<int>(n,0));
        dp[n-1]=triangle[n-1];
        for(int i=n-2;i>=0;i--){
            for(int j=0;j<=i;j++){
                dp[i][j]=triangle[i][j]+min(dp[i+1][j],dp[i+1][j+1]);
            }
        }
        return dp[0][0];
    }
};