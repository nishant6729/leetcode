class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size();
        int i=0;
        int j=1;
        int sidx=0;
        while(j<n){
            while(j<n && nums[i]==nums[j]){
                j++;
            }
            if(j-i>=2){
                nums[sidx]=nums[i];
                sidx+=1;
                nums[sidx]=nums[i];
                
            }
            
            if(j<n){
                sidx++;
                nums[sidx]=nums[j];
                i=j;
                j=i+1;
            }
        }
        ;
        return sidx+1;

    }
};