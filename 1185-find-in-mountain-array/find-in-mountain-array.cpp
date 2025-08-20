class Solution {
public:
    int findInMountainArray(int target, MountainArray &arr) {
        int n = arr.length();
        int peakIdx = -1;

  
        int lo = 0, hi = n - 1;
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            int midVal = arr.get(mid);
            int nextVal = arr.get(mid + 1);
            if (midVal < nextVal) {
                lo = mid + 1;
            } else {
                hi = mid;
            }
        }
        peakIdx = lo; 
        
        lo = 0, hi = peakIdx;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            int midVal = arr.get(mid);
            if (midVal == target) return mid;
            else if (midVal < target) lo = mid + 1;
            else hi = mid - 1;
        }

        
        lo = peakIdx + 1, hi = n - 1;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            int midVal = arr.get(mid);
            if (midVal == target) return mid;
            else if (midVal > target) lo = mid + 1; 
            else hi = mid - 1;
        }

        return -1;
    }
};
