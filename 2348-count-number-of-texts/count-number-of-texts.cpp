class Solution {
public:
    int dp[100001];
    int helper(string& s,int i,int n){
        if(dp[i]!=-1) return dp[i];
        if(i==n) return 1;
        if(s[i]=='1' || s[i]=='0') return 0;
        long long onetake=0;
        long long twotake=0;
        long long threetake=0;
        long long fourtake=0;
        if(s[i]>='2' && s[i]<='9'){
            onetake=1LL * helper(s,i+1,n);
        }
        if(i+1<n){
            if(s[i]==s[i+1]){
                twotake=1LL * helper(s,i+2,n);
            }
        }
        if(i+2<n){
            if((s[i]==s[i+1]) && (s[i+1]==s[i+2])){
                threetake=1LL * helper(s,i+3,n);
            }
        }
        if(s[i]=='7' || s[i]=='9'){
            if(i+3<n){
                if((s[i]==s[i+1] && (s[i+1]==s[i+2] && s[i+2]==s[i+3]))){
                    fourtake=1LL * helper(s,i+4,n);
                }
            }
        }
        int ans=(onetake+twotake+threetake+fourtake)%(1000000007);
        return dp[i]=ans;
    }
    int countTexts(string s) {
        memset(dp,-1,sizeof(dp));
        int n=s.size();
        int ans=helper(s,0,n);
        return ans;
    }
};