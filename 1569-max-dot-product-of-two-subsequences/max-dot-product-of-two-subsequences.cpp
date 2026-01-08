class Solution {
public:
    int m,n;

    int dp[501][501];

    int helper(vector<int>& nums1,vector<int>& nums2,int i,int j){
        if(i>=m || j>=n) return -1e9;

        if(dp[i][j]!=-1e9) return dp[i][j];


        int val=nums1[i]*nums2[j];

        int take_i_j=(nums1[i]*nums2[j])+helper(nums1,nums2,i+1,j+1);

        int take_i=helper(nums1,nums2,i,j+1);

        int take_j=helper(nums1,nums2,i+1,j);

        int dont_take=helper(nums1,nums2,i+1,j+1);

        return dp[i][j]=max({val,take_i_j,take_i,take_j,dont_take});

    }
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        m=nums1.size();
        n=nums2.size();

        for(int i=0;i<501;i++){
            for(int j=0;j<501;j++){
                dp[i][j]=-1e9;
            }
        }
        return helper(nums1,nums2,0,0);
    }
};