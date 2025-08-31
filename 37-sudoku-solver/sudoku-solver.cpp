class Solution {
public:
    bool isValid(vector<vector<char>>& board,int i,int j,char d){
        for(int k=0;k<9;k++){
            if(board[i][k]==d) return false;   // us row ke sare cols explore
            if(board[k][j]==d) return false;    // us col ke sare rows explore
        }

        int startI=i/3*3;   // start row no of that particular grid
        int startJ=j/3*3;   // start col no of that particular grid

        for(int k=0;k<3;k++){
            for(int l=0;l<3;l++){
                if(board[startI+k][startJ+l]==d) return false;   // traverse through all the elements of that block 
            }
        }
        return true;
    }
    bool solve(vector<vector<char>>& board){
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]=='.'){
                    for(char d='1';d<='9';d++){
                        if(isValid(board,i,j,d)){
                            board[i][j]=d;    // try all possible valid char for that particular cell 

                            if(solve(board)==true) return true;   // if saatisfy all the cells that is complete board then true 
 
                            board[i][j]='.';    // otherwise backtrack it to original . and try for diff combinations 
                         }
                    }
                    return false;  // . hai or true nhi mil paa rha 
                }
                
            }
        } 
        return true;    // . hi nhi hai agar hoti toh pehle hi true ya false mil jata  
    }
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);   // chlo sara explore krenge 
    }
};