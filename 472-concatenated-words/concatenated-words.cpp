class Solution {
public:
    unordered_set<string> container;
    
    bool helper(string& s,int idx,vector<int>& dp){
        
        if(idx==s.size()) return true;
        if(idx!=0 && container.find(s.substr(idx,s.size()-idx))!=container.end()) return true;
        if(dp[idx]!=-1) return dp[idx];
        int n=s.size();
        for(int l = 1; idx + l <= n; ++l){
        string temp = s.substr(idx, l);
        if(container.count(temp) && helper(s, idx + l, dp))
            return dp[idx] = true;
        }
        return dp[idx]=false;
    }
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        for(auto& s:words){
            container.insert(s);
        }
        vector<string> ans;
        for(auto& s:words){
            container.erase(s);
            vector<int> dp(s.size()+1,-1);
            if(helper(s,0,dp)) ans.push_back(s);
            container.insert(s);
        }
        return ans;
    }
};