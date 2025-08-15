class Solution {
public:
    bool isValid(const string &s1,const string &s2){
        if (s1.size() != s2.size()) return false;
        int diffs = 0;
        for (int i = 0; i < (int)s1.size(); ++i) {
            if (s1[i] != s2[i]) {
                if (++diffs > 1) return false;
            }
        }
        return diffs == 1;
    }
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
        unordered_set<string> s;
        for(auto& c:wordList){
            s.insert(c);
        }
        if(s.find(endWord)==s.end()) return 0;
        
        queue<string> qu;
        qu.push(beginWord);
        int c=0;
        
        while(!qu.empty()){
            int k=qu.size();
            
            while(k--){
                string f=qu.front();
                qu.pop();
                
                for (auto it = s.begin(); it != s.end();) {
                    if (isValid(f, *it)) {
                        if (*it == endWord) {
                                return c + 2;
                        }
                        qu.push(*it);
                        it = s.erase(it); // erase returns next iterator — safe
                    }    
                    else {
                        ++it;
                    }
                }
            }
            c++;
            
        }
        return 0;
    }
};