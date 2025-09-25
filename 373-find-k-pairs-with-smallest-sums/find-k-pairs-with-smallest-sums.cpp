class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int m=nums1.size();
        int n=nums2.size();
        set<pair<int,int>> st;
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>> >pq;

        pq.push({nums1[0]+nums2[0],{0,0}});
        st.insert({0,0});
        vector<vector<int>> ans;
        while(!pq.empty() && k>0){
            int i=pq.top().second.first;
            int j=pq.top().second.second;
            pq.pop();
            ans.push_back({nums1[i],nums2[j]});
            k--;
            if(i+1<m){
                if(!(st.count({i+1,j})))
                {
                    pq.push({nums1[i+1]+nums2[j],{i+1,j}});
                    st.insert({i+1,j});
                }
            }
            if(j+1<n){
                if(!(st.count({i,j+1})))
               {     pq.push({nums1[i]+nums2[j+1],{i,j+1}});
                    st.insert({i,j+1});}
            }


        }
        
        return ans;

    }
};