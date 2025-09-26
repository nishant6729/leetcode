class Solution {
public:
    unordered_set<string> st;
    unordered_map<string,bool> mp;
    bool helper(string& s,string ans,int idx){
        if(idx==s.size()){
            return ans.empty() || st.count(ans);
        }
        string key=to_string(idx)+'_'+ans;
        if(mp.find(key)!=mp.end()) return mp[key];
        ans=ans+s[idx];
        if(st.find(ans)==st.end()){
            
            return mp[key]=helper(s,ans,idx+1);
        }
        else{
            
            return mp[key]=helper(s,ans,idx+1) || helper(s,"",idx+1);
        }
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        
        for(auto& word:wordDict){
            st.insert(word);
        }
        bool ans=helper(s,"",0);
        return ans;
    }
};