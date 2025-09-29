class Solution {
public:

    string longestPalindrome(string s) {
        int n=s.size();
        if (n == 0) return "";
        vector<vector<int>> dp(n,vector<int>(n,-1));


        for(int L=1;L<=n;L++){
            for(int i=0;i<n;i++){
                int j=i+L-1;
                if(j>=n) break;
                if(L==1){
                    dp[i][j]=1;
                }
                else if(L==2 && s[i]==s[j]){
                    dp[i][j]=2;
                }
                else{
                    if(s[i]==s[j] && dp[i+1][j-1]!=-1){
                        dp[i][j]=L;
                    }
                }
            }
        }
        int maxIdx=-1;
        int maxVal=INT_MIN;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(dp[i][j]!=-1){
                    if(dp[i][j]>maxVal){
                        maxIdx=i;
                        maxVal=dp[i][j];
                    }
                }
            }
        }
        return s.substr(maxIdx,maxVal);
    }
};