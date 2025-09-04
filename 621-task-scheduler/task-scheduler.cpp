class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        priority_queue<pair<int,char>> pq;
        unordered_map<char,int> mp;
        unordered_map<char,int> temp;
        for(auto ch:tasks){
            mp[ch]=-1;
            temp[ch]++;
        }
        for(auto p:temp){
            pq.push({p.second,p.first});
        }
        int count=0;
        int curr=0;
        while(!pq.empty()){
            auto t=pq.top();
            int freq=t.first;
            char ele=t.second;
            pq.pop();
            if(mp[ele]==-1){
                count++;
                mp[ele]=curr;
                if(freq-1>0){
                    pq.push({freq-1,ele});
                }
                
            }
            else{
                if(curr-mp[ele]-1>=n){
                    count++;
                    mp[ele]=curr;
                    if(freq-1>0){
                        pq.push({freq-1,ele});
                    }
                }
                else{
                    stack<pair<int,char>> st;
                    st.push(t);
                    while((!pq.empty() && curr-mp[pq.top().second]-1<n) && mp[pq.top().second]!=-1){
                        st.push(pq.top());
                        pq.pop();
                    }
                    if(pq.empty()){
                        count++;
                    }
                    else{
                        count++;
                        auto temp=pq.top();
                        mp[temp.second]=curr;
                        pq.pop();
                        if(temp.first-1>0){
                            pq.push({temp.first-1,temp.second});
                        }
                    }
                    while(!st.empty()){
                        pq.push(st.top());
                        st.pop();
                    }
                }
            }
            curr++;
        }
        return count;
    }
};