class Solution {
public:
    int min_Kadane(vector<int>& nums){
        int curr=nums[0];
        int best=nums[0];

        for(int i=1;i<nums.size();i++){
            curr=min(curr+nums[i],nums[i]);
            best=min(best,curr);
        }
        return best;
    }
    
    int max_Kadane(vector<int>& nums){
        int curr=nums[0];
        int best=nums[0];

        for(int i=1;i<nums.size();i++){
            curr=max(curr+nums[i],nums[i]);
            best=max(best,curr);
        }
        return best;
    }
    int maxSubarraySumCircular(vector<int>& nums) {
        int totalSum=accumulate(nums.begin(),nums.end(),0);
        int normalMaxSubArraySum=max_Kadane(nums);

        int circularSubArrayMaxSum=totalSum-min_Kadane(nums);

        if(circularSubArrayMaxSum>0){
            return max(circularSubArrayMaxSum,normalMaxSubArraySum);
        }
        return normalMaxSubArraySum;
    }
};