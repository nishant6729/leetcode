class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double sum=0;
        int i=0;
        int j=0;
        for(;j<k;j++){
            sum+=nums[j];
        }
        double best=sum;
        while(j<nums.size()){
            sum-=nums[i];
            i++;
            sum+=nums[j];
            best=max(best,sum);
            j++;
        }
        double ans=best/k;
        return ans;
    }
};