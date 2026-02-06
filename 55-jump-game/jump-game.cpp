class Solution {
public:
    bool canJump(vector<int>& nums) {
        // consider max Jump only and see ki me wha tk pahuch skta ya nhi agr aage tk pahuch skta then is tk bhi pahuch skta 


        int maxIdx=0;

        for(int i=0;i<nums.size();i++){
            if(i>maxIdx) return false;   // yha tk toh aa hi skta 

            maxIdx=max(maxIdx,i+nums[i]); // kitna max jaa skta hu pura max stretch hai isme 
        }

        return true;
    }
};