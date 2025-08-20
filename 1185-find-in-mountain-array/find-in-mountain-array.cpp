class Solution {
public:
    int findInMountainArray(int target, MountainArray &arr) {
        int n = arr.length();
        int peakIdx = -1;

        // Step 1: Find peak using binary search
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
        peakIdx = lo; // peak found

        // Step 2: Binary search on ascending part
        lo = 0, hi = peakIdx;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            int midVal = arr.get(mid);
            if (midVal == target) return mid;
            else if (midVal < target) lo = mid + 1;
            else hi = mid - 1;
        }

        // Step 3: Binary search on descending part
        lo = peakIdx + 1, hi = n - 1;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            int midVal = arr.get(mid);
            if (midVal == target) return mid;
            else if (midVal > target) lo = mid + 1; // reversed because it's descending
            else hi = mid - 1;
        }

        return -1;
    }
};
