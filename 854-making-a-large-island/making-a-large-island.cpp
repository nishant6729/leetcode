class DisjointSet{
public:
        int n;

        vector<int> size;
        vector<int> parent;
        DisjointSet(int n){
            size.resize(n+1,1);
            parent.resize(n+1);

            for(int i=0;i<=n;i++){
                parent[i]=i;
            }

        }
        int findParent(int n){
            if(parent[n]==n) return n;
            return parent[n]=findParent(parent[n]);
        }
        void DoUnion(int a,int b){
            a=findParent(a);
            b=findParent(b);

            if(a==b)  return;

            if(size[a]<=size[b]){
                parent[a]=b;
                size[b]+=size[a];
            }
            else{
                parent[b]=a;
                size[a]+=size[b];
            }

           
        }
};
class Solution {
public:
    vector<vector<int>> dir={{-1,0},{1,0},{0,1},{0,-1}};
    bool isValid(int row,int col,int n){
        if(row>=0 && row<n && col>=0 && col<n) return true;
        else return false;
    }
    int largestIsland(vector<vector<int>>& grid) {
        
        int n=grid.size();

        DisjointSet ds(n*n+1);
        // grid ke har ek cell ko ek unit ki tarah treat kro toh is hisab se cells=n*n

        // har cell ka no nikalne ka formula =(current row no)*(total col ka count)+current col ka no

        for(int row=0;row<n;row++){
            for(int col=0;col<n;col++){
                if(grid[row][col]==1){
                    for(auto& d:dir){
                        int newRow=row+d[0];
                        int newCol=col+d[1];

                        int oldCellNo=row*n+col;

                        int newCellNo=newRow*n+newCol;

                        if(isValid(newRow,newCol,n) && grid[newRow][newCol]==1){
                            ds.DoUnion(oldCellNo,newCellNo);
                        }
                    }
                }   
            }
        }
        int ans=0;
        for(int row=0;row<n;row++){
            for(int col=0;col<n;col++){
                int cellNo=row*n+col;


                ans=max(ans,ds.size[cellNo]);
            }
        }
         for(int row=0;row<n;row++){
            for(int col=0;col<n;col++){
                if(grid[row][col]==0){
                    unordered_set<int> cells;

                    for(auto& d:dir){
                        int newRow=row+d[0];
                        int newCol=col+d[1];

                        int oldCellNo=row*n+col;

                        int newCellNo=newRow*n+newCol;

                        if(isValid(newRow,newCol,n)){
                            if(grid[newRow][newCol]==1){
                                cells.insert(ds.findParent(newCellNo));

                            }
                        }
                    }
                    int s=1;
                    for(auto& cell:cells){
                        s+=ds.size[cell];
                    }
                    ans=max(ans,s);
                }   
            }
        }
        return ans;
        

    }
};