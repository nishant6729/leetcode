class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0;i<9;i++){
            unordered_set<int> st;
            for(int j=0;j<9;j++){
                if(board[i][j]=='.') continue;
                int temp=board[i][j]-'0';
                if((temp<1 || temp>9) || st.count(temp)){
                    return false;
                }
                else{
                    st.insert(temp);
                }
            }
        }
        for(int i=0;i<9;i++){
            unordered_set<int> st;
            for(int j=0;j<9;j++){
                if(board[j][i]=='.') continue;
                int temp=board[j][i]-'0';
                if((temp<1 || temp>9) || st.count(temp)){
                    return false;
                }
                else{
                    st.insert(temp);
                }
            }
        }
        for(int block=0;block<9;block++){

            unordered_set<int> st;

            int startRow=3*(block/3);
            int startCol=3*(block%3);

            for(int i=0;i<3;i++){
                for(int j=0;j<3;j++){
                    if(board[startRow+i][startCol+j]=='.') continue;
                    int temp=board[startRow+i][startCol+j]-'0';
                    if((temp<1 || temp>9) || st.count(temp)){
                        return false;
                    }
                    else{
                        st.insert(temp);
                    }
                }
            }
        }
        return true;

    }
};