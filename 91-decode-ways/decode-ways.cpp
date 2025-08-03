class Solution {
public:
    int dp[101];
    int helper(string& s,int idx,int n){
        if(dp[idx]!=-1) return dp[idx];
        if(idx==n) return 1;
        if(s[idx]=='0') return 0;
        int firsttaken=helper(s,idx+1,n);
        int twotaken=0;
        if(idx+1<n){
            if(s[idx]=='1' || (s[idx]=='2'&& s[idx+1]<='6')){
                twotaken=helper(s,idx+2,n);
            }
        }
        return dp[idx]=firsttaken+twotaken;
    }
    int numDecodings(string s) {
        memset(dp,-1,sizeof(dp));
        int n=s.size();
        int ans=helper(s,0,n);
        return ans;
    }
};