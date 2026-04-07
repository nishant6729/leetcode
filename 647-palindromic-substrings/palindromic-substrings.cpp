class Solution {
public:
    int countSubstrings(string s) {
        vector<vector<int>> dp(s.size()+2,vector<int>(s.size()+2,0));

        int cnt=0;

        for(int i=1;i<=s.size();i++){
            dp[1][i]=1;
        }
        for(int len=2;len<=s.size();len++){
            
            for(int i=0;i<s.size();i++){
                if(len==2){
                    if(i<s.size()-1) dp[len][i]=(s[i]==s[i+1]);
                }
                else{
                    int j=i+len-1;

                    if(j>=s.size()) break;

                    if(s[i]==s[j] && dp[len-2][i+1]==1){
                        dp[len][i]=1;
                    }
                }
                
            }
        }

        for(int i=0;i<=s.size();i++){
            for(int j=0;j<=s.size();j++){
                if(dp[i][j]==1) cnt++;
            }
        }
        return cnt;
    }
};