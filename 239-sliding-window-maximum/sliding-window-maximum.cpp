class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        multiset<int> st;

        vector<int> ans;

        
        for(int i=0;i<k-1;i++){
            st.insert(nums[i]);
        }
        int i=0;
        int j=k-1;

        int n=nums.size();
        while(j<n){
            st.insert(nums[j]);
            ans.push_back(*st.rbegin());
            st.erase(st.find(nums[i]));            
            i++;
            j++;
        }
        return ans;
    }
};