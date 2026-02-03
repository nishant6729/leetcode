class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int count=0;
        bool increasing=true;

        int n=nums.size();

        if(nums[n-2]==nums[n-1]) return false;
        for(int i=1;i<nums.size()-1;i++){

            if(nums[i]==nums[i-1]) return false;
            
            if(nums[i]>nums[i-1] && nums[i]>nums[i+1]){
                if(increasing){
                    count++;
                    increasing=false;
                }
                else return false;
            }
            else if(nums[i]<nums[i-1] && nums[i]<nums[i+1]){
                if(!increasing){
                    count++;
                    increasing=true;
                }
                else return false;
            }
        }

        return count==2;
    }
};