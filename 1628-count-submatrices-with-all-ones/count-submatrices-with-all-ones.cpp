class Solution {
public:
    int helper(vector<int>& v){
        int n=v.size();
        stack<int> st;
        stack<int> gt;
        vector<int> nsi(n);
        vector<int> psi(n);
        psi[0]=-1;
        st.push(0);
        for(int i=1;i<n;i++){
            while(!st.empty() && v[st.top()]>=v[i]) st.pop();
            if(st.empty()) psi[i]=-1;
            else psi[i]=st.top();
            st.push(i);
        }
        gt.push(n-1);
        nsi[n-1]=n;
        for(int i=n-2;i>=0;i--){
            while(!gt.empty() && v[gt.top()]>v[i]) gt.pop();
            if(gt.empty()) nsi[i]=n;
            else nsi[i]=gt.top();
            gt.push(i);
        }

        int count=0;
        for(int i=0;i<n;i++){
            if(v[i]==0) continue;
            int n1=nsi[i]-i;
            int n2=i-psi[i];
            count+=v[i]*n1*n2;
        }
        return count;
    }
    int numSubmat(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        vector<int> v(n);
        int count=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==0) v[j]=0;
                else v[j]+=mat[i][j];
            }
            for(auto ele:v){
                cout<<ele<<" ";
            }
            cout<<endl;
            count+=helper(v);
        }
        return count;
    }
};