class Solution {
public:
    int findMaxArea(vector<int>& height){
        int n=height.size();
        vector<int> nsr(n);
        vector<int> nsl(n);
        nsl[0]=-1;
        nsr[n-1]=n;
        stack<int> st;
        st.push(0);
        for(int i=1;i<n;i++){
            while(!st.empty() && height[st.top()]>=height[i]) st.pop();
            if(st.empty()) nsl[i]=-1;
            else nsl[i]=st.top();
            st.push(i);
        }
        stack<int> gt;
        gt.push(n-1);
        for(int i=n-2;i>=0;i--){
            while(!gt.empty() && height[gt.top()]>=height[i]) gt.pop();
            if(gt.empty()) nsr[i]=n;
            else nsr[i]=gt.top();
            gt.push(i);
        }
        int maxArea=0;
        for(int i=0;i<n;i++){
            int h=height[i];
            int width=nsr[i]-nsl[i]-1;
            maxArea=max(maxArea,h*width);
        }
        return maxArea;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        // key concept sochne wali thi ki kis tarah ise hum maxArea histogram me convert kre 
        // har row ke liye dekhte jao or cummalative matrix bnao har baar or max store kro
        int m=matrix.size();
        int n=matrix[0].size();

        vector<int> height(n);
        for(int i=0;i<n;i++){
            height[i]=(matrix[0][i]=='1')?1:0;
        }
        int maxArea=findMaxArea(height);
        for(int row=1;row<m;row++){
            for(int col=0;col<n;col++){
                if(matrix[row][col]=='0') height[col]=0;
                else{
                    height[col]+=1;
                }
            }
            maxArea=max(maxArea,findMaxArea(height));
        }
        return maxArea;
    }
};