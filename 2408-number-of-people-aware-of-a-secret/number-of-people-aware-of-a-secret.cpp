class Solution {
public:
    int MOD=1e9+7;
    int peopleAwareOfSecret(int n, int delay, int forget) {
        vector<int> dp(n+1);
        dp[1]=1;  // on day 1 ek hi bande ko pta tha
        for(int i=2;i<=n;i++){
            // har ith day pe kitne logo ko pta hai

            int count=0;
            for(int j=i-forget+1;j<=i-delay;j++){
                if(j>0) {
                    count=(count+dp[j])%MOD;
                }
                
            }
            dp[i]=count;
        }
        int result=0;
        for(int i=n-forget+1;i<=n;i++){
            if(i>0){
                result=(result+dp[i])%MOD;
            }
        }
        return result;
    }
};