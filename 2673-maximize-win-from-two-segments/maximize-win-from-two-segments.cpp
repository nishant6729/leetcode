class Solution {
public:
    int maximizeWin(vector<int>& nums, int k) {
        int n=nums.size();
        int start=0;
        vector<int> dp(n);
        int ans=0;
        for(int end=0;end<n;end++){
            while(nums[end]-nums[start]>k) start++;
            int curr_ans=end-start+1;
            if(start>0) curr_ans+=dp[start-1];
            ans=max(ans,curr_ans);
            int pahle=0;
            if(end>0){
                pahle=dp[end-1];
            }
            dp[end]=max(end-start+1,pahle);
            
        }
        return ans;
    }
};