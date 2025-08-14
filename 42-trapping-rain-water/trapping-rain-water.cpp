class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        vector<int> leftMax(n);
        vector<int> rightMax(n);
        leftMax[0]=height[0];
        rightMax[n-1]=height[n-1];
        for(int i=1;i<n;i++){
            leftMax[i]=max(leftMax[i-1],height[i]);
        }
        for(int i=n-2;i>=0;i--){
            rightMax[i]=max(rightMax[i+1],height[i]);
        }
        int count=0;
        for(int i=1;i<n-1;i++){
            int lmax=leftMax[i];
            int rmax=rightMax[i];
            int temp=min(lmax,rmax)-height[i];
            if(temp>0) count+=temp;
        }
        return count;
    }
};