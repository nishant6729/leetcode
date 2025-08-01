class Solution {
public:
    int dp[2001];
    bool isPalindrome[2001][2001];
    void preComputeIsPalindrome(string& s){
        int n=s.size();
        for(int i=0;i<n;i++){
            isPalindrome[i][i]=1;
        }
        for(int len=2;len<=s.size();len++){
            for(int i=0;i<n;i++){
                int j=i+len-1;
                if(j>=s.size()) break;
                if(len==2 && s[i]==s[j]){
                    isPalindrome[i][j]=true;
                }
                else{
                    isPalindrome[i][j]=((s[i]==s[j]) && isPalindrome[i+1][j-1]);
                }
            }
        }
    }
    int helper(string s,int idx){
        if(idx==s.size()) return -1;
        if(dp[idx]!=-1) return dp[idx];
        int minCuts=INT_MAX;
        for(int j=idx;j<s.size();j++){
            if(isPalindrome[idx][j]){
                minCuts=min(minCuts,1+helper(s,j+1));
            }
        }
        return dp[idx]=minCuts;
    }
    int minCut(string s) {
        //first precompute palindromes in the strings
        memset(dp,-1,sizeof(dp));
        memset(isPalindrome,false,sizeof(isPalindrome));
        preComputeIsPalindrome(s);
        int ans=helper(s,0);
        return ans;
    }
};