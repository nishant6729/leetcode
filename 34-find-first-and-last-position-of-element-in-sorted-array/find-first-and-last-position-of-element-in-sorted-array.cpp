class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int lidx=-1;
        int uidx=-1;
        int lo=0;
        int hi=nums.size()-1;
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(nums[mid]==target){
                lidx=mid;
                hi=mid-1;
            }
            else if(nums[mid]>target) hi=mid-1;
            else lo=mid+1;
        }
        lo=0;
        hi=nums.size()-1;
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(nums[mid]==target){
                uidx=mid;
                lo=mid+1;
            }
            else if(nums[mid]>target) hi=mid-1;
            else lo=mid+1;
        }
        return {lidx,uidx};
    }
};