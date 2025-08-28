class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        int i=0;
        for(int j=1;j<n;j++){  // left subtriangle diagonals
            
                int tempI=i;
                int tempJ=j;
                vector<int> temp;
                while(tempI<n && tempJ<n){
                    temp.push_back(grid[tempI][tempJ]);
                    tempI++; 
                    tempJ++;
                }
                sort(temp.begin(),temp.end());
                tempI=i;
                tempJ=j;
                while(tempI<n && tempJ<n){
                    grid[tempI][tempJ]=temp[tempI];
                    tempI++; 
                    tempJ++;
                }
            
            
        }
        int j=0;
        for(int i=0;i<n;i++){  // left subtriangle diagonals
            
                int tempI=i;
                int tempJ=j;
                vector<int> temp;
                while(tempI<n && tempJ<n){
                    temp.push_back(grid[tempI][tempJ]);
                    tempI++; 
                    tempJ++;
                }
                sort(temp.begin(),temp.end());
                reverse(temp.begin(),temp.end());
                tempI=i;
                tempJ=j;
                while(tempI<n && tempJ<n){
                    grid[tempI][tempJ]=temp[tempJ];
                    tempI++; 
                    tempJ++;
                }
            
            
        }
        return grid;
    }
};