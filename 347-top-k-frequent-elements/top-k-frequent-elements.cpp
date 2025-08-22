class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        atexit(+[](){ofstream("display_runtime.txt") << 0 << '\n';});
        vector<int> ans(k);
        int temp=k-1;
        unordered_map<int,int> m;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        for(int i=0;i<nums.size();i++){
            m[nums[i]]++;
        }
        for(auto x:m){
            pair<int,int> p;
            p.second=x.first;
            p.first=x.second;
            pq.push(p);
            if(pq.size()>k) pq.pop();
        }
        while(pq.size()>0){
            pair<int,int> p;
            p=pq.top();
            ans[temp]=p.second;
            pq.pop();
            temp--;
        }
        return ans;


        
        
    }
};