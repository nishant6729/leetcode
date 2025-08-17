class Solution {
public:
    string removeDuplicateLetters(string s) {
        stack<char> st;
        unordered_map<char,int> mp;
        unordered_set<char> included;
        for(auto ch:s){
            mp[ch]++;

        }
        for(int i=0;i<s.size();i++){
            char ch=s[i];
            mp[ch]--;
            if (included.find(ch) != included.end()) {
                continue; // already in stack
            }
            if(st.empty()) {
                st.push(ch);
                included.insert(ch);
            }
            else{
                while(!st.empty() && (st.top()>ch && mp[st.top()]>0)){
                    
                    included.erase(st.top());
                    st.pop();
                }
                
                st.push(ch);
                included.insert(ch);
                
            }
        }
        string ans="";
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        reverse(begin(ans),end(ans));
        return ans;
    }
};