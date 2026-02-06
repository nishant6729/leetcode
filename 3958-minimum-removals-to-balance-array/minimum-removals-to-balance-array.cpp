class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        // using sliding window find max size balanced subarray 


        sort(nums.begin(),nums.end());


        int i=0;
        int j=0;

        int n=nums.size();

        int maxSize=INT_MIN;

        while(j<n){

            long long temp=1LL*nums[i]*k;
            while(j<n && nums[j]<=temp){
                j++;
            }
            maxSize=max(maxSize,j-i);


            long long temp2=1LL*nums[i]*k;
            while((i<n && j<n ) && temp2<nums[j]){
                i++;
                temp2=1LL*nums[i]*k;
            }
        }

        return n-maxSize;
    }
};