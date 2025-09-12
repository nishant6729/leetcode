class Solution {
public:
    int maxProfit(vector<int>& nums) {
        int n=nums.size();
        vector<int> helper(n);
        helper[n-1]=nums[n-1];
        for(int i=n-2;i>=0;i--){
            helper[i]=max(nums[i],helper[i+1]);
        }
        int ans=0;
        for(int i=0;i<n;i++){
            ans=max(ans,helper[i]-nums[i]);
        }
        return ans;
    }
};