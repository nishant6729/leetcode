class Solution {
public:
    int t;
    bool helper(vector<int>& arr){
        if(t<arr[0] || t>arr[arr.size()-1]) return false;
        int lo=0;
        int hi=arr.size()-1;
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(arr[mid]==t) return true;
            if(arr[mid]>=t){
                hi=mid-1;
            }
            else{
                lo=mid+1;
            }
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        t=target;
        int m=matrix.size();
        int n=matrix[0].size();
        for(int i=0;i<m;i++){
            
            if(helper(matrix[i])) return true;
        }
        return false;
    }
};