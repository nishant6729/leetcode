class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end());
        int i=0;
        int j=1;
        int n=points.size();
        int arrow=0;
        while(i<n){
            int currStart=points[i][0];
            int currEnd=points[i][1];
            while(j<n && currEnd>=points[j][0]){
                currEnd=min(currEnd,points[j][1]);
                j++;
            }
            arrow+=1;
            i=j;
            j=i+1;
        }
        return arrow;
    }
}; 