class Solution {
public:
    string minWindow(string s, string t) {
        if(t.size()>s.size()) return "";
       int req=t.size(); 
       int i=0;
       int j=0;
       int n=s.size();
       int minLen=INT_MAX;
       int idx=0;
       unordered_map<char,int> mp;
       for(auto& c:t){
            mp[c]++;
       }
       while(j<n){
            
                mp[s[j]]--;
                if(mp[s[j]]>=0){
                    req--;
                }
                
                j++;

                while (req == 0) {
                    int currLen = j - i;
                    if (currLen < minLen) {
                        minLen = currLen;
                        idx = i;
                    }
                    // try to remove s[i]
                    mp[s[i]]++;
                    if (mp[s[i]] > 0) req++; // we lost a required char
                    i++;
                }

            
       }
        return (minLen == INT_MAX) ? "" : s.substr(idx, minLen);
    }
};