class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n=nums.size();
        // going for dp lets see
        vector<pair<int,int>> dp(n); // vector storing prev subarrays ending at this no count and their common diff
        if(n<3) return 0;
        dp[0]={0,0};
        dp[1]={0,nums[1]-nums[0]};
        for(int i=2;i<n;i++){
            if(dp[i-1].second==(nums[i]-nums[i-1])){
                dp[i].first+=dp[i-1].first+1;
                
            }
            else{
                dp[i].first=0;
            }
            dp[i].second=nums[i]-nums[i-1];
        }
        int ans=0;
        for(auto p:dp){
            ans+=p.first;
        }
        return ans;
    }   
};