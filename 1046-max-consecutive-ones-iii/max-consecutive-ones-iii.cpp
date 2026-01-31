class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int zeroCount=0;

        int n=nums.size();

        int maxLen=0;

        int i=0;

        for(int j=0;j<n;j++){
            if(nums[j]==0) zeroCount++;

            while(zeroCount>k){
                if(nums[i]==0) zeroCount--;
                i++;
            }

            maxLen=max(maxLen,j-i+1);



        }

        return maxLen;
    }
};