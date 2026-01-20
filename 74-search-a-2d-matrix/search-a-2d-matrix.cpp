class Solution {
public:
    bool BinarySearch(int rowM,vector<vector<int>>& matrix,int target){
        int lo=0;
        int hi=matrix[0].size()-1;

        while(lo<=hi){
            int mid=lo+(hi-lo)/2;

            if(matrix[rowM][mid]==target){
                return true;
            }
            else if(matrix[rowM][mid]>target){
                hi=mid-1;
            }
            else lo=mid+1;
        }

        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size();
        int n=matrix[0].size();

        int rowL=0;
        int rowH=m-1;

        int colH=n-1;
        int colL=0;

        while(rowL<=rowH){
            int rowM=rowL+(rowH-rowL)/2;


            if(matrix[rowM][colL]>target){
                rowH=rowM-1;
            }
            else if(matrix[rowM][colH]<target){
                rowL=rowM+1;
            }
            else{
                return BinarySearch(rowM,matrix,target);
            }
        }

        return false;
    }
};