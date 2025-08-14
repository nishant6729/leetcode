class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        vector<int> nsi(n);
        vector<int> psi(n);
        psi[0]=-1;
        stack<int> st;
        st.push(0);
        for(int i=1;i<n;i++){
            while(!st.empty() && heights[st.top()]>=heights[i]) st.pop();
            if(st.empty()) psi[i]=-1;
            else psi[i]=st.top();
            st.push(i);
        }
        stack<int> gt;
        gt.push(n-1);
        nsi[n-1]=n;
        for(int i=n-2;i>=0;i--){
            while(!gt.empty() && heights[gt.top()]>=heights[i]) gt.pop();
            if(gt.empty()) nsi[i]=n;
            else nsi[i]=gt.top();
            gt.push(i);
        }
        int maxArea=0;
        for(int i=0;i<n;i++){
            int height=heights[i];
            int width;
            width=nsi[i]-psi[i]-1;
            maxArea=max(maxArea,height*width);
        }
        return maxArea;
    }
};