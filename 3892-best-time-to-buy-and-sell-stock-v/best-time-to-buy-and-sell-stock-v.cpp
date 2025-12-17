class Solution {
public:
    const long long NEG = LLONG_MIN / 4;
    long long dp[501][4][1001];
    long long helper(vector<int>& prices, int k,int mode,int idx){
        
        if(idx>=prices.size()){
            if(mode==0 || mode==1) return NEG;
            return 0;
        }
        if(k==0){
            if(mode==0 || mode==1) return NEG;
            return 0;
        }
        if(dp[k][mode][idx]!=-1) return dp[k][mode][idx];
        if(mode==2){
            long long buy=helper(prices,k,0,idx+1)-prices[idx];

            long long sell=prices[idx]+helper(prices,k,1,idx+1);

            long long leave=helper(prices,k,mode,idx+1);

            return dp[k][mode][idx]=max({buy,sell,leave});
        }

        if(mode==0){
            long long sell=helper(prices,k-1,2,idx+1)+prices[idx];

            long long leave=helper(prices,k,mode,idx+1);

            return dp[k][mode][idx]=max(sell,leave);
        }

        else{
            long long buy=helper(prices,k-1,2,idx+1)-prices[idx];

            long long leave=helper(prices,k,mode,idx+1);

            return dp[k][mode][idx]=max(buy,leave);        
        
        }
    }
    long long maximumProfit(vector<int>& prices, int k) {
        memset(dp, -1, sizeof(dp));
        return helper(prices,k,2,0);
    }
};