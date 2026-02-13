class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {

        int n=graph.size();

        unordered_map<int,vector<int>> mp;
        vector<int> outdegree(n,-1);

        for(int i=0;i<n;i++){
            outdegree[i]=graph[i].size();

            for(auto& ele:graph[i]){
                mp[ele].push_back(i);  // reversed the edges
            }
        }

        queue<int> qu;

        for(int i=0;i<n;i++){
            if(outdegree[i]==0){
                qu.push(i);

                
            }
        }
        vector<int> ans;
        while(!qu.empty()){
            auto it=qu.front();

            qu.pop();

            ans.push_back(it);

            for(auto& neigh:mp[it]){
                outdegree[neigh]--;
                if(outdegree[neigh]==0){
                    qu.push(neigh);

                }
            }


        }
        sort(ans.begin(),ans.end());
        return ans;

        
        

        
    }
};