class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size();
        int sidx=1;
        int i=0;
        int j=1;
        while(j<n){
            while(j<n && nums[i]==nums[j]){
                j++;
            }
            if(j<n){
                nums[sidx]=nums[j];
                i=j;
                j=i+1;
                sidx++;
            }
        }
        nums.erase(nums.begin()+sidx,nums.end());
        return sidx;
    }
};