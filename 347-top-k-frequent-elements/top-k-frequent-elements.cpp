class Solution {
public:
    typedef pair<int,int> P;
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> freq;


        vector<int> ans;
        for(auto& num:nums){
          freq[num]++;
        }

        priority_queue<P,vector<P>,greater<P>> pq;

        for(auto& p:freq){
            if(pq.size()<k){
                pq.push({p.second,p.first});
            }

            else{
                if(pq.top().first<p.second){
                    pq.pop();
                    pq.push({p.second,p.first});
                }
            }
        }


        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;
    }
};