class Solution {
public:
    bool check(vector<int>& nums) {
        int n=nums.size();
        bool flag=false;
        int max=INT_MAX;
        for(int i=0;i<=n-1;i++){
            if(i<n-1 && nums[i]>nums[i+1]){
                if(!flag){
                    flag=true;
                    max=nums[0];
                }
                else{
                    return false;
                }
            }
            else if(nums[i]>max){
                return false;
            }
        }
        return true;
    }
};