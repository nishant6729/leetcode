class Solution {
public:
    bool search(vector<int>& arr, int target) {
        // Code Here
        // Har index ke ek side proper sorted part and ek side unsorted 
        //       |
        //       |
        // Hum focus krenge on the sorted part 
        
        int n=arr.size();
        
        int lo=0;
        
        int hi=n-1;
        
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            
            
            if(arr[mid]==target) return true;
            
            else if(arr[mid]==arr[lo] && arr[mid]==arr[hi]){
                lo++;
                hi--;
            }
            else if(arr[mid]<=arr[hi]){
                if(target>arr[mid] && target<=arr[hi]) lo=mid+1;
                else hi=mid-1;
            }
            
            else{
                if(target>=arr[lo] && target<arr[mid]) hi=mid-1;
                else lo=mid+1;
            }
            
        
        }
        
        return false;
    }
};