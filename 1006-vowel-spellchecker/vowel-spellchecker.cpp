class Solution {
public:
    // minimal helpers: don't modify input in-place
    string to_lower(const string &s){
        string r = s;
        transform(r.begin(), r.end(), r.begin(), ::tolower);
        return r;
    }
    string vowelConvert(string s){ // takes by value, returns devoweled string
        for (char &c : s) {
            if (c=='a' || c=='e' || c=='i' || c=='o' || c=='u')
                c = '*';
        }
        return s;
    }

    // (kept for reference; you can remove if unused)
    bool CapitalizationMatch(const string &word, const string &query){
        if(word.size()!=query.size()) return false;
        string w = to_lower(word);
        string q = to_lower(query);
        return q==w;
    }
    bool VowelsMatch(const string &word, const string &query){
        if(word.size()!=query.size()) return false;
        string w = to_lower(word);
        string q = to_lower(query);
        for (int i = 0; i < (int)q.size(); ++i) {
            bool qv = (q[i]=='a' || q[i]=='e' || q[i]=='i' || q[i]=='o' || q[i]=='u');
            bool wv = (w[i]=='a' || w[i]=='e' || w[i]=='i' || w[i]=='o' || w[i]=='u');
            if (qv) {
                if (!wv) return false;
            } else {
                if (w[i] != q[i]) return false;
            }
        }
        return true;
    }

    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        unordered_set<string> exact;
        unordered_map<string,string> lowerMapped;
        unordered_map<string,string> vowelMapped;

        // build maps using original words (don't mutate wordlist)
        for (const string &w : wordlist) {
            exact.insert(w);                       // exact match uses original word
            string lw = to_lower(w);
            if (lowerMapped.find(lw) == lowerMapped.end())
                lowerMapped[lw] = w;              // store first occurrence (original case)
            string dv = vowelConvert(lw);
            if (vowelMapped.find(dv) == vowelMapped.end())
                vowelMapped[dv] = w;              // store first occurrence (original case)
        }

        int n = queries.size();
        vector<string> ans(n);
        for (int i = 0; i < n; ++i) {
            const string &query = queries[i];

            // 1) exact
            if (exact.find(query) != exact.end()) {
                ans[i] = query;
                continue;
            }

            // 2) capitalization-insensitive
            string lq = to_lower(query);
            auto it = lowerMapped.find(lq);
            if (it != lowerMapped.end()) {
                ans[i] = it->second;
                continue;
            }

            // 3) vowel-error-insensitive (devowel)
            string dq = vowelConvert(lq);
            auto it2 = vowelMapped.find(dq);
            if (it2 != vowelMapped.end()) {
                ans[i] = it2->second;
            } else {
                ans[i] = "";
            }
        }
        return ans;
    }
};
