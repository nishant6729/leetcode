class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size()>nums2.size()) return findMedianSortedArrays(nums2,nums1);  // choti size wale pe kaam krna hai 
        int m=nums1.size();
        int n=nums2.size();

        int lo=0;  
        int hi=m;  // BS on no of elements from nums1 in left direction

        while(lo<=hi){
            int Px=lo+(hi-lo)/2;  // nums1 ke kitne element left portion me aaenge jispe hum kaam krne wale


            int Qx=(m+n+1)/2-Px ;// nums2 ke ele in left portion
            //left side
            int x1=(Px==0)?INT_MIN : nums1[Px-1];   //left side me koi nhi hai khali pda hai 
            int x2=(Qx==0)?INT_MIN : nums2[Qx-1];
            //right side
            int x3=(Px==m) ? INT_MAX :nums1[Px];
            int x4=(Qx==n) ? INT_MAX :nums2[Qx];

            if(x1<=x4 && x2<=x3){
                if((m+n)%2==0){
                    return (max(x1,x2)+min(x3,x4))/2.0;     //left ka last and right ka first taki median calc ho ske
                } 
                else{
                    return max(x1,x2);
                }
            }
            else if(x1>x4){
                hi=Px-1;   //jyda element le liye the left me 
            }
            else lo=Px+1;
        }
        return -1;
    }
};