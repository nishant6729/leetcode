class Solution {
public:
    typedef long long ll;
    int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,int>> pq;    // pichla yi-xi max krne ke liye or pair isliye ki purana xi ka track ho k wali condition check krne ke liye
        int n=points.size();
        ll ans=LLONG_MIN;
        for(int j=0;j<n;j++){
            // j curr point ko indicate krega 
            // j ke points fixed or i prev ke points ko indicate krega toh uske liye hum optimal point search kr rhe 
            ll yj=points[j][1];
            ll xj=points[j][0];


            while(!pq.empty() && xj-pq.top().second>k){
                pq.pop();
            }

            if(!pq.empty()){
                auto temp=pq.top();
                ans=max(ans,xj+yj+temp.first);
            }


            pq.push({yj-xj,xj});   // xj purana bn jaega aage jake toh xi ka track rkhne ke liye
        }
        return ans;
    }
};