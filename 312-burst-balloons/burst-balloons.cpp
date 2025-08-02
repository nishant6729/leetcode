class Solution {
public:
    int dp[302][302];
    int helper(vector<int>& nums,int i,int j){
        if(i>j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int ans=INT_MIN;
        for(int k=i;k<=j;k++){
            ans=max(ans,nums[k]*nums[i-1]*nums[j+1]+helper(nums,i,k-1)+helper(nums,k+1,j));
        }
        return dp[i][j]=ans;
    }
    int maxCoins(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        // Really Tough Question
        int n=nums.size();
        nums.push_back(1);
        nums.insert(nums.begin(),1);
        int ans=helper(nums,1,n);
        return ans;
    }
};