class Solution {
public:
    vector<int> ans;
    vector<vector<int>> nums;
    int m;
    int n;
    bool isValidRow(int i){
        if(i>=m || i<0) return false;
        return true;
    }
    bool isValidCol(int j){
         if(j>=n || j<0) return false;
         return true;
    }
    void helper(int i,int j,int flag,int curr){
        if(!isValidRow(i) || !isValidCol(j)) return;
        if(curr>=m*n) return;
        if(ans[m*n-1]!=-1) return ;
        ans[curr]=nums[i][j];
        curr++;
        int nextI;
        int nextJ;

        if(flag==1){  // upward movement

            nextI=i-1;
            nextJ=j+1;

            if(isValidRow(nextI) && isValidCol(nextJ)){
                helper(nextI,nextJ,1,curr);
            }
            else if(!isValidRow(nextI) && !isValidCol(nextJ)){
                
                helper(i+1,j,0,curr);
            }
            else{
                if(!isValidRow(nextI))               // top hit, move right
                    helper(i, j+1, 0, curr);
                else                                   // right hit, move down
                    helper(i+1, j, 0, curr);

            }

        }
        else{   // downward movement
            nextI=i+1;
            nextJ=j-1;

            if(isValidRow(nextI) && isValidCol(nextJ)){
                helper(nextI,nextJ,0,curr);
            }
            else if(!isValidRow(nextI) && !isValidCol(nextJ)){
                helper(i,j+1,1,curr);
            }
            else{
                if(!isValidRow(nextI))               // bottom hit, move right
                    helper(i, j+1, 1, curr);
                else                                   // left hit, move down
                    helper(i+1, j, 1, curr);
            }
        }
       
    }
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        
        m=mat.size();
        n=mat[0].size();

        vector<int> temp(m*n,-1);
        ans=temp;
        nums=mat;
        helper(0,0,1,0);
        return ans;
    }
};