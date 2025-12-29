class Solution {
public:
    unordered_map<string,bool> memo;
    bool solve(string curr,int idx,unordered_map<string,vector<char>>& mp,string above){
        if(curr.size()==1){
            return true;
        }
        if(idx==curr.size()-1){
            return solve(above,0,mp,"");
        }
        string key=curr +'_' + to_string(idx) + '_' +above;

        if(memo.find(key)!=memo.end()) return memo[key]; 
        string temp=curr.substr(idx,2);

        if(mp.find(temp)==mp.end()){
            return memo[key]=false;
        }

        for(auto& c:mp[temp]){
            above.push_back(c);

            if(solve(curr,idx+1,mp,above)) return memo[key]=true;

            above.pop_back();    
        }

        return memo[key]=false;

    }
    bool pyramidTransition(string bottom, vector<string>& allowed) {
        // first baar sochne pe maine idx pe baare me socha hi nhi

        // backtracking me single chars wise use krna hoga 

        unordered_map<string,vector<char>> mp;

        for(auto& s:allowed){
            mp[s.substr(0,2)].push_back(s[2]);
        } 

        // solve(curr,idx,mp,above)
        return solve(bottom,0,mp,"");
    }
};