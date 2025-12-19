class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> time(n+1,INT_MAX);

        unordered_map<int,vector<pair<int,int>> > adj;

        for(auto& v:times){
            adj[v[0]].push_back({v[1],v[2]});  //{source:-{dst,time}}
        }
        set<pair<int,int>> st;  //{time,node}
        
        time[k]=0;

        st.insert({0,k});

        while(!st.empty()){
            auto it=*(st.begin());

            st.erase(it);

            int currTime=it.first;
            int currNode=it.second;

            for(auto& neigh:adj[currNode]){
                if(currTime+neigh.second<time[neigh.first]){
                    if(time[neigh.first]!=INT_MAX){
                        st.erase({time[neigh.first],neigh.first});
                    }
                    time[neigh.first]=currTime+neigh.second;
                    st.insert({currTime+neigh.second,neigh.first});
                }
            }

            
        }
        int ans=INT_MIN;    
        for(int i=1;i<=n;i++){
            if(time[i]==INT_MAX) return -1;

            ans=max(ans,time[i]);
        }

        return ans;
    }
};