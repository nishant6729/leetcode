class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string,int> mp;
        for(auto s:words){
            mp[s]++;
        }
        auto lambda=[](const pair<int,string>& a,const pair<int,string>& b){
            if(a.first==b.first){
                return a.second<b.second;
            }
            else return a.first>b.first;
        };
        priority_queue<pair<int,string>,vector<pair<int,string>>,decltype(lambda) > pq(lambda);
        for(auto p:mp){
            if(pq.size()==k){
                if(p.second>pq.top().first){
                    pq.pop();
                    pq.push({p.second,p.first});
                }
                else if(p.second==pq.top().first && p.first<pq.top().second){
                    pq.pop();
                    pq.push({p.second,p.first});
                }
                else{
                    continue;
                }
            } 
            else{
                pq.push({p.second,p.first});
            }
            

        }
        vector<string> ans;
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};