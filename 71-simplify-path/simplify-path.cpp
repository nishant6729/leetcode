class Solution {
public:
    string simplifyPath(string path) {
        vector<string> words;
        int i=1;
        int j=1;
        int n=path.size();
        while(j<n){
            while(j<n && path[j]!='/'){
                j++;
            }

            
            string temp=path.substr(i,j-i);
            if(temp!="") words.push_back(temp);
            while(j<n && path[j]=='/') j++;
            i=j;

        }
        stack<string> st;
        for(auto& s:words){
            if(s==".." && !st.empty()) st.pop();
            if(s==".") continue;
            else if(s!="..") st.push(s);

        }
        stack<string> st1;
        while(!st.empty()){
            st1.push(st.top());
            st.pop();
        }
        string ans="";
        if(st1.empty()) return "/";
        while(!st1.empty()){
            ans+='/';
            ans+=st1.top();
            
            st1.pop();
        }
        
        return ans;
    }
};