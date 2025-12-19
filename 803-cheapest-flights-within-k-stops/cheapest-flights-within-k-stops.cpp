class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {

        unordered_map<int,vector<pair<int,int>>> adj;
        for(auto& v:flights){
            adj[v[0]].push_back({v[1],v[2]});
        }

        vector<vector<int>> dist(n, vector<int>(k+2, INT_MAX));
        dist[src][0] = 0;

        set<pair<int,pair<int,int>>> st; // {cost,{stops,node}}
        st.insert({0,{0,src}});

        while(!st.empty()){
            auto it = *st.begin();
            st.erase(st.begin());

            int currD = it.first;
            int currK = it.second.first;
            int node  = it.second.second;

            if(currK > k) continue;

            for(auto& neigh:adj[node]){
                int nextNode = neigh.first;
                int w = neigh.second;

                int nextStops = currK + 1;
                int nextCost  = currD + w;

                if(nextStops <= k+1 && nextCost < dist[nextNode][nextStops]){
                    dist[nextNode][nextStops] = nextCost;
                    st.insert({nextCost,{nextStops,nextNode}});
                }
            }
        }

        int ans = INT_MAX;
        for(int i=0;i<=k+1;i++){
            ans = min(ans, dist[dst][i]);
        }

        return ans == INT_MAX ? -1 : ans;
    }
};
