class Solution {
public:
    int maxArea(vector<int>& height) {
        // for max Area max width and max height
        int n=height.size();
        int i=0;
        int j=n-1;
        int maxArea=INT_MIN;
        while(i<j){
            int width=j-i; // max width make sure

            int h=min(height[i],height[j]);

            int area=width*h;
            maxArea=max(area,maxArea);

            if(height[i]<height[j]){
                i++; // choti height reject krke or cases explore kro
            }
            else{
                j--;
            }

        }
        return maxArea;
    }
};