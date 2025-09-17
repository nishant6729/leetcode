class Solution {
public:
    bool isPossible(int mid,int k,vector<int>& nums){
        int house=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<=mid){
                house++;
                i++;
            }
            
        }
        if(house>=k) return true;
        return false;
    }
    int minCapability(vector<int>& nums, int k) {
        // jab bhi minimize the maximum ya maximize the minimum dikhe then binary search on answer is used 
        int lo=*min_element(nums.begin(),nums.end());
        int hi=*max_element(nums.begin(),nums.end());
        int result;
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;

            if(isPossible(mid,k,nums)){
                result=mid;
                hi=mid-1;
            }
            else{
                lo=mid+1;
            }
        }
        return result;
    }
};