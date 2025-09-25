class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // classical level wala question 
        // Binary search kis kis tarah se use ho skta btata hai 

        if(nums1.size()>nums2.size()){ 
            return findMedianSortedArrays(nums2,nums1);     // choti size wale pe binary search lgana hai 
        }
        int m=nums1.size();
        int n=nums2.size();

        int lo=0;
        int hi=m;    // kitne element left portion of final array me aaenge nums 1 se uska max

        while(lo<=hi){
            int Px=lo+(hi-lo)/2;   // left portion me itne ele me liye nums1 se

            int Qx=(m+n+1)/2-Px;

            int x1=(Px==0)?INT_MIN:nums1[Px-1];  // left side me last ele of nums1

            int x2=(Qx==0)?INT_MIN:nums2[Qx-1];  // left side me last ele from nums2

            int x3=(Px==m)?INT_MAX:nums1[Px];       // sare left me chle gye toh right me kya hai

            int x4=(Qx==n)?INT_MAX:nums2[Qx];


            if(x1<=x4  && x2<=x3){   // shi bn rha hai sb kuch 
                if((m+n)%2==0){
                    return (max(x1,x2)+min(x3,x4))/2.0;
                }
                else{
                    return max(x1,x2);
                }
            }
            if(x1>x4){   // jyda ele le liye nums1 se 
                hi=Px-1;
            }
            else{
                lo=Px+1;  // km element pd gye nums1 se left side me or nums2 se jyda aa gye 
            }
        }
        return -1;
    }
};