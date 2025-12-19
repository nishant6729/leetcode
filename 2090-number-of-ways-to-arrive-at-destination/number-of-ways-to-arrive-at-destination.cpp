class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        const int MOD = 1e9 + 7;

        unordered_map<int,vector<pair<int,int>> > adj;

        for(auto& road:roads){
            adj[road[0]].push_back({road[1],road[2]});  // src->{dst,time}

            adj[road[1]].push_back({road[0],road[2]});
        }

        set<pair<long long,pair<int,int>> > st;  //{time,{currNode,prevNode}}

        st.insert({0,{0,-1}});

        vector<long long> time(n,LLONG_MAX);
        vector<int> ways(n,0);
        time[0]=0;
        ways[0]=1;
        int count=0;
        while(!st.empty()){
            auto it=*(st.begin());

            st.erase(it);

            long long currTime=it.first;
            int currNode=it.second.first;
            int prevNode=it.second.second;

            if(currTime>time[currNode]) continue;

            for(auto& neigh:adj[currNode]){
                int thatNode=neigh.first;
                int thatTime=neigh.second;

                

                long long newTime=currTime+thatTime;

                if(newTime<time[thatNode]){

                   
                    time[thatNode]=newTime;
                    ways[thatNode]=ways[currNode];
                    st.insert({time[thatNode],{thatNode,currNode}});
                }
                else if(newTime==time[thatNode]){
                    ways[thatNode]=(ways[currNode]+ways[thatNode])%MOD;
                   
                }
            }
        }

        return ways[n-1];
    }
};