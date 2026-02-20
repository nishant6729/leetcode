class Solution {
public:
    string shortestCommonSupersequence(string s1, string s2) {
        // DP bhrna is necessary to know ki kis direction me string create krna hai 

        int m=s1.size();

        int n=s2.size();


        vector<vector<int>> dp(m+1,vector<int>(n+1,0));

        for(int i=0;i<=m;i++){
            for(int j=0;j<=n;j++){  // 1 based indexing consider krke bhrna start DP ko

                if(i==0 || j==0) dp[i][j]=i+j; // agr koi ek empty then dusre ki size is req

                else if(s1[i-1]==s2[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];  // is bnde ko liya ab bakiyo ka dekh lo
                }

                else{
                    dp[i][j]=1+min(dp[i-1][j],dp[i][j-1]);   // dono me se ek bnda lo jiske lene pe baaki ka creation min me ho
                }
                 
            }
        }
       
        // SIMPLE RULE : DP bnana upr se niche DP se use krke string bnana niche se upr

        string ans="";

        int i=m;
        int j=n;

        while(i>0 && j>0){
            if(s1[i-1]==s2[j-1]){
                ans+=s1[i-1];

                i--;
                j--;
            }
            else{
                if(dp[i-1][j]<dp[i][j-1]){  // ith bnde ko lena is beneficial
                    ans+=s1[i-1];
                    i--;
                }
                else{
                    ans+=s2[j-1];  // jth bnde ko lena is beneficial
                    j--;
                }
            }
        }
        
        while(i>0){
            ans+=s1[i-1];
            i--;
        }
        while(j>0){
            ans+=s2[j-1];
            j--;
        }
        reverse(ans.begin(),ans.end());
        return ans;

    }
};