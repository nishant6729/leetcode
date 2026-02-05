class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n=nums.size();
        vector<int> result(n);
        for(int i=0;i<nums.size();i++){
            if(nums[i]>0){
                int newIdx=(i+nums[i])%n;
                result[i]=nums[newIdx];
            }
            else if(nums[i]<0){
                int newIdx=(i-abs(nums[i])+n)%n;
                if(newIdx<0) newIdx+=n;
                result[i]=nums[newIdx];
            }
            else result[i]=nums[i];
        }

        return result;
    }
};