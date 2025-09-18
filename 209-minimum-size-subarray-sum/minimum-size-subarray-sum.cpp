class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int i=0;
        int n=nums.size();
        int j=0;
        int sum=0;
        int minSize=INT_MAX;
        int currSize;
        while(j<n){
            sum+=nums[j];
            while(sum>=target){
                currSize=j-i+1;
                minSize=min(minSize,currSize);
                sum-=nums[i];
                i++;
            }
            j++;
        }
        if(minSize==INT_MAX) return 0;
        return minSize;
    }
};