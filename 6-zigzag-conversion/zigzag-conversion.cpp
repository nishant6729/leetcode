class Solution {
public:
    vector<vector<char>> ans;
    int rows;
    int col;
    void fillHelper(string& s,int i,int j,int currMov,int idx){
        if(idx>=s.size()) return;
        ans[i][j]=s[idx];
        if(currMov==0){//down
            if(i+1<rows){
                fillHelper(s,i+1,j,0,idx+1);
            }
            else{
                fillHelper(s,i-1,j+1,1,idx+1);
            }
        }
        else{//zig zag
            if(i-1>=0 && j+1<col){
                fillHelper(s,i-1,j+1,1,idx+1);
            }
            else{
                fillHelper(s,i+1,j,0,idx+1);
            }
        }
    }
    string convert(string s, int numRows) {
        int n=s.size()+1;
        rows=numRows;
        if(numRows==1) return s;
        col=n;
        vector<vector<char>> temp(numRows,vector<char>(n,'_'));
        ans=temp;
        fillHelper(s,0,0,0,0);
        string result="";
        
        for(int i=0;i<numRows;i++){
            for(int j=0;j<n;j++){
                if(ans[i][j]!='_') result+=ans[i][j];
            }
        }
        return result;
    }
};