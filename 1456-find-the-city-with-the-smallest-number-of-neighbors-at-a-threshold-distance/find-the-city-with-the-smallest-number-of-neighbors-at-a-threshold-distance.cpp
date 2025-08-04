class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        unordered_map<int,vector<pair<int,int>> >adj;
        
        for(auto& edge : edges){
            int src=edge[0];
            int dst=edge[1];
            int wt=edge[2];
            adj[src].push_back({dst,wt});
            adj[dst].push_back({src,wt});
        }
        vector<int> reachableNodes(n);
        for(int src=0;src<n;src++){
            vector<int> dis(n,INT_MAX);
            dis[src]=0;
            priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
            pq.push({0,src});
            while(!pq.empty()){
                auto [d,u]=pq.top();
                pq.pop();
                if(d>dis[u]) continue;
                for(auto& neigh:adj[u]){
                    int v=neigh.first;
                    int w=neigh.second;
                    if(d+w<dis[v] && d+w<=distanceThreshold){
                        dis[v] = d + w;
                        pq.push({dis[v], v});
                    }
                }
            }
            int cnt=0;
            for(int i=0;i<n;i++){
                if(i==src) continue;
                if(dis[i]<=distanceThreshold) cnt++;
            }
            reachableNodes[src]=cnt;
        }
         int bestCity = -1;
        int bestCount = INT_MAX;
        for (int i = 0; i < n; i++) {
            if (reachableNodes[i] <= bestCount) {
                // Note: <= so that in tie, the larger i overwrites smaller
                bestCount = reachableNodes[i];
                bestCity = i;
            }
        }
        return bestCity;
    }
};