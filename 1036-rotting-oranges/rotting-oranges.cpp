class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int minute=0;
        queue<pair<int,int>> qu;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2){
                    qu.push({i,j});
                }
            }
        }
        while(!qu.empty()){
            int k=qu.size();
            while(k--){
                auto temp=qu.front();
                qu.pop();
                int row=temp.first;
                int col=temp.second;
                if(row-1>=0){
                    if(grid[row-1][col]==1){
                        grid[row-1][col]=2;
                        qu.push({row-1,col});
                    }
                }
                if(row+1<m){
                    if(grid[row+1][col]==1){
                        grid[row+1][col]=2;
                        qu.push({row+1,col});
                    }
                }
                if(col-1>=0){
                    if(grid[row][col-1]==1){
                        grid[row][col-1]=2;
                        qu.push({row,col-1});
                    }
                }
                if(col+1<n){
                    if(grid[row][col+1]==1){
                        grid[row][col+1]=2;
                        qu.push({row,col+1});
                    }
                }
            }
            minute++;
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1) return -1;
            }
        }
        if(minute==0) return minute;
        return minute-1;
    }
};