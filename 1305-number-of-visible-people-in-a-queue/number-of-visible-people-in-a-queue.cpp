class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        int n=heights.size();
        stack<int> st;
        vector<int> ans(n);
        st.push(heights[n-1]);
        ans[n-1]=0;
        for(int i=n-2;i>=0;i--){
            int ele=heights[i];
            int count=0;
            while(!st.empty() && st.top()<=ele){
                st.pop();
                count++;
            }
            if(!st.empty() && st.top()>ele){
                count++;
            }
            ans[i]=count;
            st.push(ele);
        }
        return ans;
    }
};