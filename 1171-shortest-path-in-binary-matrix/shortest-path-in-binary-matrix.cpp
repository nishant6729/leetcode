class Solution {
public:
    vector<vector<int>> dir={{-1,0},{1,0},{0,1},{0,-1},{-1,-1},{1,1},{-1,1},{1,-1}};
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        // implementation of Djisktra's Algorithm
        // only difference is edge weight here is always one
        
        int n=grid.size();

        if(grid[0][0]==1 || grid[n-1][n-1]==1) return -1;

        
        vector<vector<int>> dist(n,vector<int>(n,INT_MAX));

        dist[n-1][n-1]=1;

        set<pair<int,pair<int,int>>> st;

        st.insert({1,{n-1,n-1}});

        while(!st.empty()){
            auto it=*(st.begin());

            int distance=it.first;

            int i=it.second.first;
            int j=it.second.second;

            st.erase(it);

            for(auto& d:dir){
                int newI=i+d[0];
                int newJ=j+d[1];

                if(newI>=0 && newI<n && newJ>=0 && newJ<n && grid[newI][newJ]==0){
                    if(distance+1<dist[newI][newJ]){

                        if(dist[newI][newJ]!=INT_MAX){
                            st.erase({dist[newI][newJ],{newI,newJ}});     // htao jiski need nhi hai set me se 
                        }
                        dist[newI][newJ]=distance+1;

                        st.insert({distance+1,{newI,newJ}});
                    }
                }
            }
        }

        if(dist[0][0]==INT_MAX) return -1;
        return dist[0][0];
    }
};