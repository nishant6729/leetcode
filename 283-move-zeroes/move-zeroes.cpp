class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int idx=0;

        int i=0;

        int n=nums.size();

        while(i<n){
            if(nums[i]!=0){
                nums[idx]=nums[i];
                idx++;
            }
            i++;
        }
        for(int i=idx;i<n;i++){
            nums[i]=0;
        }

        
    }
};