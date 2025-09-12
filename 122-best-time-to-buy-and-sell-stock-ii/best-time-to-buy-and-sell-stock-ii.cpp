class Solution {
public:
    int dp[30001][3];
    int helper(vector<int>& prices,int idx,bool purchase){
        if(idx>=prices.size()) return 0;
        if(dp[idx][purchase]!=-1) return dp[idx][purchase];
        if(purchase){
            int buy=helper(prices,idx+1,false)-prices[idx];
            int not_buy=helper(prices,idx+1,true);
            return dp[idx][purchase]=max(buy,not_buy);
        }
        else{
            int sell=prices[idx]+helper(prices,idx+1,true);
            int not_sell=helper(prices,idx+1,false);
            return dp[idx][purchase]=max(sell,not_sell);
        }
    }
    int maxProfit(vector<int>& prices) {
        memset(dp, -1, sizeof(dp));
        return helper(prices,0,true);
    }
};