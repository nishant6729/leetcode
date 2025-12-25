class Solution {
public:
    vector<vector<int>> dir={{-1,0},{1,0},{0,1},{0,-1}};
    int swimInWater(vector<vector<int>>& grid) {
        // 
        int n=grid.size();
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>> >pq;
        vector<vector<int>> dist(n,vector<int>(n,INT_MAX));
         dist[0][0]=grid[0][0];
        pq.push({grid[0][0],{0,0}});

        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();
            int currTime=it.first;

            int i=it.second.first;
            int j=it.second.second;

            if(currTime>dist[i][j]) continue;

           

            if(i==n-1 && j==n-1){
                return currTime;
            }
            for(auto& d:dir){
                int newI=i+d[0];
                int newJ=j+d[1];

                
                if(newI>=0 && newI<n && newJ>=0 && newJ<n){
                    int newTime=max(currTime,grid[newI][newJ]);
                    if(newTime < dist[newI][newJ]){
                        dist[newI][newJ] = newTime;  
                        pq.push({newTime,{newI,newJ}});
                    }
                }
            }
        }
        return -1;
    }
};