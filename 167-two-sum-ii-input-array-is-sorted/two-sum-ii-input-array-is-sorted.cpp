class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int curr=0;
        int j=curr+1;
        int k=nums.size()-1;

        while(curr<nums.size()){
            j=curr+1;
            int temp=target-nums[curr];
            if(temp>=nums[j] && temp<=nums[k]){
                int lo=j;
                int hi=k;
                while(lo<=hi){
                    int mid=lo+(hi-lo)/2;
                    if(nums[mid]==temp){
                        return {curr+1,mid+1};
                    }
                    else if(nums[mid]<temp){
                        lo=mid+1;
                    }
                    else{
                        hi=mid-1;
                    }
                }
            }
            curr++;
        }
        return {-1,-1};
    }
};  