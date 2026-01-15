class Solution {
public:
    int searchInsert(vector<int>& arr, int target) {
       int lower_bound=arr.size();
        
        int lo=0;
        int hi=arr.size()-1;
        
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            
            if(arr[mid]>=target){
                lower_bound=mid;
                hi=mid-1;
            }
            else lo=mid+1;
        }
        
        return lower_bound;
    }
};