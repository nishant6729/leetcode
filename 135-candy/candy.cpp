class Solution {
public:
    int candy(vector<int>& nums) {
        // aage se then piche se 
        int n=nums.size();
        vector<int> ans(n,1);
        for(int i=1;i<n;i++){ // piche wale ko check kro 
            if(nums[i-1]<nums[i]){
                ans[i]=max(ans[i],ans[i-1]+1);
            }
        }
        for(int i=n-2;i>=0;i--){ // aage wale ko check kro 
            if(nums[i+1]<nums[i]){
                ans[i]=max(ans[i],ans[i+1]+1);
            }
        }
        return accumulate(ans.begin(),ans.end(),0);
    }
};