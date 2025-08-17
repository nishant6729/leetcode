class Solution {
public:
    int longestValidParentheses(string s) {
        int n=s.size();
        stack<pair<char,int>> st;
        vector<int> v(n);
        for(int i=0;i<n;i++){
            char ch=s[i];
            if(ch=='('){
                st.push({ch,i});
            }
            else{
                if(!st.empty()){
                    auto temp=st.top();
                    int idx=temp.second;
                    v[idx]=1;
                    v[i]=1;
                    st.pop();
                }
            }
        }
        int best=0;
        int count=0;
        for(int i=0;i<n;i++){
            if(v[i]==1){
                count++;
                 best=max(best,count);}
            else{
               
                count=0;
            }
        }
        return best;
    }
};