class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int maxArea=INT_MIN;
        double maxDiagonal=INT_MIN;
        int n=dimensions.size();
        for(auto v:dimensions){
            int l=v[0];
            int w=v[1];


            double diagonal=sqrt(l*l+w*w);
            
            int area=l*w;
            if(diagonal>maxDiagonal){
                maxDiagonal=diagonal;
                
                maxArea=area;
            }
            else if(diagonal==maxDiagonal){
                maxArea=max(area,maxArea);
            }
        }
        return maxArea;
    }
};