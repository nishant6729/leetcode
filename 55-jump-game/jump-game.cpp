class Solution {
public:
    int dp[10001];
    bool helper(vector<int>& nums,int idx){
        if(idx>=nums.size()-1) return dp[idx]=true;
        if(nums[idx]==0) return dp[idx]=false;


        if(dp[idx]!=-1) return dp[idx];
        bool ans=false;
        for(int jump=1;jump<=nums[idx];jump++){
            if(helper(nums,idx+jump)) return dp[idx]=true;
        }

        return dp[idx]=false;
    }   
    bool canJump(vector<int>& nums) {
        
        memset(dp,-1,sizeof(dp));
        return helper(nums,0);
    }
};