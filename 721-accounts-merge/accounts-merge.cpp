class DisjointSet{
public:
        int n;

        vector<int> size;
        vector<int> parent;
        DisjointSet(int n){
            size.resize(n+1,1);
            parent.resize(n+1);

            for(int i=0;i<=n;i++){
                parent[i]=i;
            }

        }
        int findParent(int n){
            if(parent[n]==n) return n;
            return parent[n]=findParent(parent[n]);
        }
        void DoUnion(int a,int b){
            a=findParent(a);
            b=findParent(b);

            if(a==b)  return;

            if(size[a]<=size[b]){
                parent[a]=b;
                size[b]+=size[a];
            }
            else{
                parent[b]=a;
                size[a]+=size[b];
            }

           
        }
};
class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n=accounts.size();
        DisjointSet ds(n+1);
        unordered_map<int,set<string>> mp;
        
        for(int i=0;i<n;i++){
            for(int j=1;j<accounts[i].size();j++){
                mp[i].insert(accounts[i][j]);
            }
        }

        for(int i=0;i<n;i++){
            for(int j=1;j<accounts[i].size();j++){
                for(int k=i+1;k<n;k++){
                    for(int l=1;l<accounts[k].size();l++){
                        if(accounts[i][j]==accounts[k][l]){
                            ds.DoUnion(i,k);
                        }
                    }
                }
            }
        }

        for(int i=0;i<n;i++){
            if(ds.findParent(i)!=i){
                for(auto& ele:mp[i]){
                    mp[ds.parent[i]].insert(ele);
                }
            }
        }
        vector<vector<string>> ans;
        for(int i=0;i<n;i++){
            if(ds.parent[i]==i){
                vector<string> temp;
                temp.push_back(accounts[i][0]);
                for(auto& ele:mp[i]){
                    temp.push_back(ele);
                }
                ans.push_back(temp);
            }
        }
        return ans;
    }
};