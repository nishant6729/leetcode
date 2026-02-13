class Solution {
public:
    vector<vector<int>> dir={{-1,0},{1,0},{0,1},{0,-1}};
    typedef pair<int,pair<int,int>> P;
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m=heights.size();

        int n=heights[0].size();

        if(m==1 && n==1) return 0;
        vector<vector<int>> maxEffort(m,vector<int>(n,INT_MAX));

        priority_queue<P,vector<P>,greater<P>> pq;


        pq.push({0,{0,0}});

        while(!pq.empty()){

            auto it=pq.top();

            pq.pop();

            int currEffort=it.first;

            int i=it.second.first;

            int j=it.second.second;

            for(auto& d:dir){
                int newI=i+d[0];
                int newJ=j+d[1];

                if(newI>=0 && newI<m && newJ>=0 && newJ<n){

                    int newEffort=max(abs(heights[newI][newJ]-heights[i][j]),currEffort);
                    if(newEffort<maxEffort[newI][newJ]){
                        maxEffort[newI][newJ]=newEffort;
                        pq.push({newEffort,{newI,newJ}});
                    }
                }
            }
        }

        
        return maxEffort[m-1][n-1];

    }
};