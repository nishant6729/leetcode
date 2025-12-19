class Solution {
public:
    vector<vector<int>> dir={{1,0},{-1,0},{0,1},{0,-1}};
    int minimumEffortPath(vector<vector<int>>& heights) {
        //direct implementation of Djisktra's Algorithm

        int row=heights.size();

        int col=heights[0].size();

        vector<vector<int>> effort(row,vector<int>(col,INT_MAX));

        effort[0][0]=0;


        set<pair<int,pair<int,int>>> st;

        st.insert({0,{0,0}});

        while(!st.empty()){
            auto it= *(st.begin());

            st.erase(it);

            int h=it.first;

            int i=it.second.first;
            int j=it.second.second;

            for(auto& d:dir){
                int newI=i+d[0];
                int newJ=j+d[1];
                
                if(newI>=0 && newI<row && newJ>=0 && newJ<col){
                    int newEffort = max(h,abs(heights[newI][newJ] - heights[i][j]));


                    if(newEffort<effort[newI][newJ]){

                        if(effort[newI][newJ]!=INT_MAX){
                            st.erase({effort[newI][newJ],{newI,newJ}});
                        }
                        effort[newI][newJ]=newEffort;

                        st.insert({newEffort,{newI,newJ}});
                    }
                }
            }
        }

        if(effort[row-1][col-1]==INT_MAX) return -1;

        return effort[row-1][col-1];
    }
};