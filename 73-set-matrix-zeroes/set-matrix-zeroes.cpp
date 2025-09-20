class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        vector<vector<int>> temp;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]==0){
                    temp.push_back({i,j});
                }
            }
        }
        for(auto& v:temp){
                    int i=v[0];
                    int j=v[1];
                    int currRow=i;
                    int currCol=j;
                    while(currRow>=0){
                        matrix[currRow][j]=0;
                        currRow--;
                        
                    }
                    currRow=i+1;
                    while(currRow<m){
                        matrix[currRow][j]=0;
                        currRow++;
                    }
                    while(currCol>=0){
                        matrix[i][currCol]=0;
                        currCol--;
                        
                    }
                    currCol=j;
                    while(currCol<n){
                        matrix[i][currCol]=0;
                        currCol++;
                    }
        }
    }
};