class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        int n=nums.size();
        if(n==1 || n==2){
            return accumulate(nums.begin(),nums.end(),0);
        }
        vector<int> dp(n,-1);

        dp[n-1]=nums[n-1];
        dp[n-2]=nums[n-2]+nums[n-1];


        multiset<pair<int,int>> st;
        st.insert({nums[n-1],n-1});
        st.insert({dp[n-2],n-2});
        for(int i=n-3;i>=0;i--){
            while (!st.empty() && st.rbegin()->second > i + k) {
                st.erase(std::prev(st.end()));
            }
            int req=(*st.rbegin()).first;
            dp[i]=nums[i]+req;
            st.insert({dp[i],i});
        }
        return dp[0];
    }
};