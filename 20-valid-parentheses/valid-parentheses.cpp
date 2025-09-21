class Solution {
public:
    bool isValid(string s) {
        
        stack<char> st;
        for(char& c:s){

            if(c=='(' || c=='{' || c=='['){
                st.push(c);
            }
            else{
                if(c==')'){
                    if(st.empty()) return false;
                    if(st.top()!='(') return false;
                    else st.pop();
                }
                else if(c=='}'){
                    if(st.empty()) return false;
                    if(st.top()!='{') return false;
                    else st.pop();
                }
                else{
                    if(st.empty()) return false;
                    if(st.top()!='[') return false;
                    else st.pop();
                }
            }
        }
        if(!st.empty()) return false;
        return true;
    }
};