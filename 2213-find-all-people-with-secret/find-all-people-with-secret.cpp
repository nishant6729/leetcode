class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        unordered_map<int,vector<pair<int,int>>> mp;

        for(auto& v:meetings){
            mp[v[0]].push_back({v[1],v[2]});  // src->{dst,time}
            mp[v[1]].push_back({v[0],v[2]});
        }

        set<pair<int,int>> st;  // {time,node}
        st.insert({0,0});
        st.insert({0,firstPerson});

        


        unordered_set<int> visited;

        while(!st.empty()){
            auto it=*(st.begin());

            st.erase(it);

            int currTime=it.first;
            int currNode=it.second;

            if(visited.find(currNode)!=visited.end()){
                continue;
            }
            
            else{
                visited.insert(currNode);
                for(auto& neigh:mp[currNode]){
                    int thatTime=neigh.second;
                    int thatNode=neigh.first;

                    if(thatTime>=currTime){
                        st.insert({thatTime,thatNode});
                    }
                }
            }
        }

        vector<int> ans;

        for(auto& ele:visited){
            ans.push_back(ele);
        }

        return ans;
    }
};