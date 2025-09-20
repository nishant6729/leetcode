class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        // Trick:Transpose and reverse row wise
        // for transpose swap upper triangle element with lower triangle element 

        // Transpose nikalo
        for(int i=0;i<matrix.size();i++){
            for(int j=i;j<matrix[0].size();j++){
                swap(matrix[i][j],matrix[j][i]);
            }
        }

        //Reverse Row wise

        for(int i=0;i<matrix.size();i++){
            reverse(matrix[i].begin(),matrix[i].end());
        }
        
    }   
};