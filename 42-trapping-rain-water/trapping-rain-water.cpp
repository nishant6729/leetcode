class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        vector<int> leftMax(n);
        vector<int> rightMax(n);
        leftMax[0]=0;
        for(int i=1;i<n;i++){
            leftMax[i]=max(leftMax[i-1],height[i-1]);
        }
        rightMax[n-1]=0;
        for(int i=n-2;i>=0;i--){
            rightMax[i]=max(rightMax[i+1],height[i+1]);
        }
        int ans=0;
        for(int i=1;i<n-1;i++){
            int temp=min(rightMax[i],leftMax[i]);
            if(temp-height[i]>0){
                ans+=temp-height[i];
            }
        }
        return ans;
    }
};