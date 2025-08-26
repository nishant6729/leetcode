class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        priority_queue<pair<double,int>> pq;
        int n=dimensions.size();
        for(int i=0;i<n;i++){
            int l=dimensions[i][0];
            int w=dimensions[i][1];

            double diagonal=sqrt(l*l+w*w);
            int area=w*l;

            pq.push({diagonal,area});
        }

        return pq.top().second;
    }
};