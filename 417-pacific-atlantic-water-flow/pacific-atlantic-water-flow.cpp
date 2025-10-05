class Solution {
public:
    vector<vector<int>> dir={{1,0},{-1,0},{0,-1},{0,1}};
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        if(heights.empty() || heights[0].empty()) return {};
        int m=heights.size();
        int n=heights[0].size();
        vector<vector<int>> pacificOcean(m,vector<int>(n,0));
        vector<vector<int>> atlanticOcean(m,vector<int>(n,0));
        for(int j=0;j<n;j++){
            pacificOcean[0][j]=1;
        }
        for(int i=1;i<m;i++){
            pacificOcean[i][0]=1;
        }
        for(int i=0;i<m;i++){
            atlanticOcean[i][n-1]=1;
        }
        for(int j=0;j<n;j++){
            atlanticOcean[m-1][j]=1;
        }

        // ---- Minimal change: iterate propagation until no new cell is marked ----
        bool changed = true;
        while(changed){
            changed = false;
            // propagate pacific marks
            for(int i=0;i<m;i++){
                for(int j=0;j<n;j++){
                    if(pacificOcean[i][j]==1){
                        for(auto& v:dir){
                            int newRow=i+v[0];
                            int newCol=j+v[1];
                            if(newRow>=0 && newRow<m && newCol>=0 && newCol<n){
                                if(heights[i][j]<=heights[newRow][newCol] && pacificOcean[newRow][newCol]==0){
                                    pacificOcean[newRow][newCol]=1;
                                    changed = true;
                                }
                            }
                        }
                    }
                }
            }

            // propagate atlantic marks
            for(int i=0;i<m;i++){
                for(int j=0;j<n;j++){
                    if(atlanticOcean[i][j]==1){
                        for(auto& v:dir){
                            int newRow=i+v[0];
                            int newCol=j+v[1];
                            if(newRow>=0 && newRow<m && newCol>=0 && newCol<n){
                                if(heights[i][j]<=heights[newRow][newCol] && atlanticOcean[newRow][newCol]==0){
                                    atlanticOcean[newRow][newCol]=1;
                                    changed = true;
                                }
                            }
                        }
                    }
                }
            }
        }

        vector<vector<int>> ans;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(atlanticOcean[i][j]==1 && pacificOcean[i][j]==1){
                    ans.push_back({i,j});
                }
            }
        }
        return ans;
    }
};
