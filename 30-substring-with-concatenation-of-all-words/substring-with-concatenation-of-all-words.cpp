class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int len=words[0].size();
        int n=s.size();
        int m=words.size();
        vector<int> ans;
        unordered_map<string,int> mp;
        for(auto& word:words) mp[word]++;

        // *** CHANGED: process each offset separately (to avoid TLE)
        for(int offset=0; offset<len; offset++){            // minimal outer loop added
            int left=offset, count=0;
            unordered_map<string,int> seen;

            for(int right=offset; right+len<=n; right+=len){
                string curr=s.substr(right,len);
                if(mp.count(curr)){
                    seen[curr]++; count++;

                    // shrink if word repeats too many times
                    while(seen[curr] > mp[curr]){
                        string leftWord=s.substr(left,len);
                        seen[leftWord]--;
                        left+=len; count--;
                    }

                    if(count==m){ 
                        ans.push_back(left);
                        string leftWord=s.substr(left,len);
                        seen[leftWord]--;
                        left+=len; count--;
                    }
                }
                else{
                    seen.clear();
                    count=0;
                    left=right+len;
                }
            }
        }
        return ans;
    }
};
