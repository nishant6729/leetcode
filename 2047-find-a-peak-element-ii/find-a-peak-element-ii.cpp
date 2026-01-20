class Solution {
public:
    int findMaxIndex(int mid,vector<vector<int>>& mat,int n,int m){
        int maxIndex=0;
        int maxEle=mat[0][mid];
        for(int i=0;i<m;i++){
            if(mat[i][mid]>maxEle){
                maxEle=mat[i][mid];
                maxIndex=i;
            }
        }

        return maxIndex;
    }
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int m=mat.size();

        int n=mat[0].size();

        int lo=0;
        int hi=n-1;

        while(lo<=hi){
            int mid=lo+(hi-lo)/2;


            int maxRowIndex=findMaxIndex(mid,mat,n,m);

            int left=(mid>0) ? mat[maxRowIndex][mid-1]:-1;

            int right=(mid<n-1)? mat[maxRowIndex][mid+1]:-1;

            if(mat[maxRowIndex][mid]<left){
                hi=mid-1;
            }
            else if(mat[maxRowIndex][mid]<right){
                lo=mid+1;
            }
            else return {maxRowIndex,mid};
        }

        return {-1,-1};
    }
};