class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int idx=0;

        int i=0;
        int j=1;
        int n=nums.size();
        while(i<n && j<n){

            while(j<n && nums[i]==nums[j]){
                j++;
            }
            if(j<n && idx<n-1){
                nums[idx+1]=nums[j];
                idx++;
            }
            
            i=j;
            j=i+1;
        }

        return idx+1;
    }
};