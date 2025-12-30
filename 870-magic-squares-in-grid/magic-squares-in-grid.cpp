class Solution {
public:
    bool helper(int si,int sj,vector<vector<int>>& grid){
        int sD1=grid[si][sj]+grid[si+1][sj+1]+grid[si+2][sj+2];
        int sD2=grid[si][sj+2]+grid[si+1][sj+1]+grid[si+2][sj];

        if(sD1!=sD2) return false;

        unordered_set<int> visited;
        for(int i=si;i<=si+2;i++){
            
            for(int j=sj;j<=sj+2;j++){
                if(grid[i][j]<=9 && grid[i][j]>=1){
                    if(!visited.count(grid[i][j])) visited.insert(grid[i][j]);
                    else return false;
                }
                else return false;
            }
            
            
        }

        for(int i=si;i<=si+2;i++){
            int sum=0;
            for(int j=sj;j<=sj+2;j++){
                sum+=grid[i][j];
            }
            if(sum!=sD1) return false;
            
        }
        
        for(int j=sj;j<=sj+2;j++){
            int sum=0;
            for(int i=si;i<=si+2;i++){
                sum+=grid[i][j];
            }
            if(sum!=sD1) return false;
        }

        return true;
    }
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int count=0;
        int rowCount=grid.size();
        int colCount=grid[0].size();
        for(int i=0;i<rowCount;i++){
            for(int j=0;j<colCount;j++){
                if(rowCount-i>=3 && colCount-j>=3){  // 3*3 grid possible or not
                    if(helper(i,j,grid)) count+=1;
                }
            }
        }
        return count;
    }
};