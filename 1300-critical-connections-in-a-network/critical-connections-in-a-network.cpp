class Solution {
public:
    int timer=1;
    void dfs(int node,vector<int>& visited,vector<vector<int>>& bridges,int parent,vector<vector<int>> & adj,vector<int>& tin,vector<int>& low){

        visited[node]=1;
        tin[node]=low[node]=timer;     // intially node pe insertion yani direct jaane ka time or via minimum path jana ka time same de do
        timer++;


        for(auto& it:adj[node]){
            if(it==parent) continue;   // parent ke case me na dfs na update of low

            if(visited[it]==-1){
                // DFS ✅️ low ko update ✅️ bridge check ✅️

                // dfs bhi or baad me low bhi update 

                dfs(it,visited,bridges,node,adj,tin,low);  // bache ka dfs

                // bache ke dfs ke baad dekhenge na ki low better mil rha kya 

                low[node]=min(low[it],low[node]);

                // chance hai ki yeh jo connection hai whi bridge ho

                // node---------it  is a bridge ka check krte hai

                if(low[it]>tin[node]){    // na hone ki condition bache ka low <= parent ke tin yani bache tk me other than parent dusre way me bhi pahuch skta hu better tarike se toh yeh bridge nhi hoga uske alava bridge hoga 
                    bridges.push_back({it,node});    
                }

            }
            else{
                // DFS❌    low update ✅️   bridge check ❌


                // agar pehle se hi visited hai na toh dfs na hi woh bridge bn skta hai kyuki ek path se me aaya hu us tk dusra path yeh hai jo visited show kr rha toh woh bridge nhi bn skta nn
                

                // na dfs na check for bridge only update low

                low[node]=min(low[node],low[it]);
            }
        }

    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        // Level toh hai question ka 

        // bridges in a graph 

        // Method:- DFS

        vector<vector<int>> adj(n+1);

        for(auto& it:connections){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        vector<vector<int>> bridges;

        vector<int> visited(n+1,-1);

        vector<int> tin(n+1);     // Insertion time = parent se kitni der me pahuch gye (via parent se kitna time)

        vector<int> low(n+1);     // Parent ke alava dusri node se given node pe better time me pahuchne ka 


        dfs(0,visited,bridges,-1,adj,tin,low);

        return bridges;
    }
};