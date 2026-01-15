class Solution {
public:
    bool canBeTaken(int mid,vector<int>& nums,int threshold){
        int count=0;
        for(int i=0;i<nums.size();i++){
            count+=nums[i]/mid;
            if(nums[i]%mid!=0) count++;
        }

        return count<=threshold;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        // Direct dekh ke pta lg rha ki binary search on answer hai 


        int lo=1;
        int hi=*max_element(nums.begin(),nums.end());


        int ans=1;
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;

            if(canBeTaken(mid,nums,threshold)){
                ans=mid;
                hi=mid-1;
            }
            else lo=mid+1;
        }
        return ans;
    }
};