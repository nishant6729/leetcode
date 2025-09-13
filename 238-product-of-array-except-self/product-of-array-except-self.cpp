class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int> leftPr(n);
        vector<int> rightPr(n);
        leftPr[0]=1;
        for(int i=1;i<n;i++){
            leftPr[i]=leftPr[i-1]*nums[i-1];
        }
        rightPr[n-1]=1;
        for(int i=n-2;i>=0;i--){
            rightPr[i]=rightPr[i+1]*nums[i+1];
        }
        vector<int> ans(n);
        for(int i=0;i<n;i++){
            ans[i]=leftPr[i]*rightPr[i];
        }
        return ans;
    }
};