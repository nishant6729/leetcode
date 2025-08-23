class Solution {
public:
    typedef pair<double,vector<int>> P;
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        
        priority_queue<P> pq;
        for(auto& point:points){
            int x=point[0];
            int y=point[1];
            double dis=sqrt(x*x+y*y);
            if(pq.size()==k){
                if(pq.top().first>dis){
                    pq.pop();
                    pq.push({dis,point});
                }
            }
            else{
                 pq.push({dis,point});
            }
        }
        vector<vector<int>> ans;
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};