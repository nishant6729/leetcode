class Solution {
public:
    vector<vector<int>> adj;
    int dfs(int node,vector<int>& ans,unordered_set<int>& visited){
        if(ans[node]==1){
            return 1;
        }
        if(visited.find(node)!=visited.end()){
            ans[node]=0;
            return 0;
        }
        visited.insert(node);
        for(auto& neigh:adj[node]){
            if(!dfs(neigh,ans,visited)){
                return ans[node]=0;
            }
        }

        return ans[node]=1;

    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        adj=graph;
        int n=graph.size();

        vector<int> ans(n,-1);

        

       

        for(int i=0;i<n;i++){
            vector<int> nodes=graph[i];
            if(nodes.size()==0){
                ans[i]=1;
            }
        }

        for(int i=0;i<n;i++){

            if(ans[i]==-1){
                unordered_set<int> visited;
                ans[i]=dfs(i,ans,visited);
            }
            
            
        }
        vector<int> result;
        for(int i=0;i<ans.size();i++){
            if(ans[i]==1){
                result.push_back(i);
            }
        }

        return result;
    }
};