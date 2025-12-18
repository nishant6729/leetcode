class Solution {
public:
    vector<vector<int>> adj;
    bool dfs(int node,vector<bool>& ans,unordered_set<int>& visited){
        if(ans[node]==true){
            return true;
        }
        if(visited.find(node)!=visited.end()){
            ans[node]=false;
            return false;
        }
        visited.insert(node);
        for(auto& neigh:adj[node]){
            if(!dfs(neigh,ans,visited)){
                return ans[node]=false;
            }
        }

        return ans[node]=true;

    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        adj=graph;
        int n=graph.size();

        vector<bool> ans(n,false);

        

       

        for(int i=0;i<n;i++){
            vector<int> nodes=graph[i];
            if(nodes.size()==0){
                ans[i]=true;
            }
        }

        for(int i=0;i<n;i++){

            if(!ans[i]){
                unordered_set<int> visited;
                dfs(i,ans,visited);
            }
            
            
        }
        vector<int> result;
        for(int i=0;i<ans.size();i++){
            if(ans[i]==true){
                result.push_back(i);
            }
        }

        return result;
    }
};