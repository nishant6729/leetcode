class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        int s=languages.size();
        vector<set<int>> temp(s);
        for(int i=0;i<s;i++){
            set<int> st;
            for(auto x:languages[i]){
                st.insert(x);
            }
            temp[i]=st;
        }
        set<int> unhappy;
        for(int i=0;i<friendships.size();i++){
            int f1=friendships[i][0];
            int f2=friendships[i][1];
            f1--;
            f2--;
            if (f1 < 0 || f1 >= s || f2 < 0 || f2 >= s) continue;
            bool flag=false;
            for(auto x:temp[f1]){
                if(temp[f2].find(x)!=temp[f2].end()){
                    flag=true;
                    break;
                }
            }
            if(!flag){
                unhappy.insert(f1);
                unhappy.insert(f2);
            }
        }
        int total=unhappy.size();
        if (unhappy.empty()) return 0; 
        unordered_map<int,int> mp;
        for(auto x:unhappy){
            for(auto i:temp[x]){
                mp[i]++;
            }
            
        }
        int ans=INT_MIN;
        for(auto p:mp){
            ans=max(ans,p.second);
        }
        int finalSolution=total-ans;
        return finalSolution;
    }
};