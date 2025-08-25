class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        // nya data structure sikha MultiSet
        int n=nums.size();
        multiset<int> st;
        int i=0;   // har i se start hoke kitna bda subarray bn skta woh dekhenge
        int j=0;   // size determine krne ke liye use hoga
        

        int maxLen=0;
        while(j<n){
            st.insert(nums[j]);

            while(*st.rbegin()-*st.begin()>limit){
                st.erase(st.find(nums[i]));
                ++i;
            }
            maxLen=max(maxLen,j-i+1);
            j++;
        }
        return maxLen;
    }
};