class Solution {
public:
    string processStr(string s) {
        stack<char> st;
        for(auto c:s){
            if(c=='*'){
                if(!st.empty()) st.pop();
            }
            else if(c=='#'){   
                string temp="";
                stack<char> st2;
                while(!st.empty()){
                    st2.push(st.top());
                    temp+=st.top();
                    st.pop();
                }
                reverse(temp.begin(),temp.end());
                while(!st2.empty()){
                    st.push(st2.top());
                    st2.pop();
                }
                for(auto ch:temp){
                    st.push(ch);
                }
            }
            else if(c=='%'){
                string temp="";
                while(!st.empty()){
                    temp+=st.top();
                    st.pop();
                }
                for(auto ch:temp){
                    st.push(ch);
                }
            }
            else{
                st.push(c);
            }
        }
        string ans="";
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};