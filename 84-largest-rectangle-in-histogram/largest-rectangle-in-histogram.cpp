class Solution {
public:
    vector<int> helper1(vector<int>& heights){
        stack<int> st;
        
        int n=heights.size();

        vector<int> temp(n);

        temp[n-1]=n;

        st.push(n-1);

        for(int i=n-2;i>=0;i--){
            while(!st.empty() && heights[st.top()]>=heights[i]) st.pop();
            if(st.empty()) temp[i]=n;
            else temp[i]=st.top();
            st.push(i);
        }

        return temp;

    }
    vector<int> helper2(vector<int>& heights){
        stack<int> st;
        
        int n=heights.size();

        vector<int> temp(n);

        temp[0]=-1;

        st.push(0);

        for(int i=1;i<n;i++){
            while(!st.empty() && heights[st.top()]>=heights[i]) st.pop();
            if(st.empty()) temp[i]=-1;
            else temp[i]=st.top();
            st.push(i);
        }

        return temp;

    }
    int largestRectangleArea(vector<int>& heights) {
        // Yaad rkhna smaller indexes aate hai use me greater nhi 
        int n=heights.size();


        vector<int> nsi=helper1(heights);
        vector<int> psi=helper2(heights);

        int maxArea=0;

        for(int i=0;i<n;i++){
            int currHeight=heights[i];

            int currWidth=nsi[i]-psi[i]-1;  // dono ko include nhi isliye -1

            maxArea=max(maxArea,currHeight*currWidth);
        }

        return maxArea;
    }
};