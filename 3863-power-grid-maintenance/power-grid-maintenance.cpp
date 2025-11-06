class Solution {
public:
    int find(vector<int>& parent,int a){
        return parent[a]=(parent[a]==a)?a:find(parent,parent[a]);
    }
    void FindUnion(vector<int>& parent,vector<long long>& rank,int a,int b){
        a=find(parent,a);
        b=find(parent,b);
        if(a==b) return;
        if(rank[a]<=rank[b]){
            rank[b]+=rank[a];
            parent[a]=b;
        }
        else{
            rank[a]+=rank[b];
            parent[b]=a;
        }
    }
    vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {
        vector<int> parent(c+1);
        vector<long long> rank(c+1,1);
        for(int i=1;i<=c;i++){
            parent[i]=i;
        }
        for(auto& v:connections){
            FindUnion(parent,rank,v[0],v[1]);
        }
        for(int i=1;i<=c;i++){
            parent[i]=find(parent,i);
        }
        unordered_map<int,int> available;
        unordered_map<int,int> parentMap;
        unordered_map<int,set<int>> component;
        for(int i=1;i<=c;i++){
            available[i]=1;
        }
        for(int i=1;i<=c;i++){
            parentMap[i]=parent[i];
        }
        for(auto& p:parentMap){
            component[p.second].insert(p.first);
        }
        vector<int> ans;
        for(auto& query:queries){
            if(query[0]==2){
                int x =query[1];
                available[x]=0;
                int temp=parentMap[x];
                component[temp].erase(x);
            }
            else{
                int x=query[1];
                if(available[x]==1) ans.push_back(x);
                else{
                    int temp=parentMap[x];
                    if(component[temp].size()==0) ans.push_back(-1);
                    else{
                        ans.push_back(*(component[temp].begin()));
                    }
                }
                
            }
        }
        return ans;
    }
};