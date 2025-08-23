class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        // implementation of ngr
        int n=temp.size();
        stack<int> st;
        st.push(n-1);
        vector<int> ans(n);
        vector<int> ngi(n);
        ngi[n-1]=n-1;
        for(int i=n-2;i>=0;i--){
            while(!st.empty() && temp[st.top()]<=temp[i]){
                st.pop();
            }
            if(st.empty()){
                ngi[i]=i;
            }
            else{
                ngi[i]=st.top();
            }
            st.push(i);
        }
        for(int i=0;i<n;i++){
            ans[i]=ngi[i]-i;

        }
        return ans;
    }
};