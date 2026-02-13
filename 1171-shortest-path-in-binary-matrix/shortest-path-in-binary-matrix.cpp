class Solution {
public:
    typedef pair<int,pair<int,int>> P;
    vector<vector<int>> dir={{-1,0},{1,0},{0,1},{0,-1},{1,1},{1,-1},{-1,1},{-1,-1}};
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();

        if(grid[0][0]==1 || grid[n-1][n-1]==1) return -1;

        priority_queue<P,vector<P>,greater<P>> pq;

        pq.push({0,{0,0}});

        vector<vector<int>> dist(n,vector<int>(n,INT_MAX));

        dist[0][0]=0;

        while(!pq.empty()){
            auto it=pq.top();

            pq.pop();

            int currCount=it.first;
            int i=it.second.first;
            int j=it.second.second;

            for(auto& d:dir){
                int newI=i+d[0];
                int newJ=j+d[1];

                if(newI>=0 && newI<n && newJ>=0 && newJ<n){
                    if(currCount+1<dist[newI][newJ] && grid[newI][newJ]==0){
                        dist[newI][newJ]=currCount+1;
                        pq.push({currCount+1,{newI,newJ}});
                    }
                }
            }


        }
        if(dist[n-1][n-1]==INT_MAX) return -1;
        return dist[n-1][n-1]+1;

    }
};