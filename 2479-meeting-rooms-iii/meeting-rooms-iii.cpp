class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>> >pq;

        set<pair<long long,int>> st;

        vector<long long> rooms(n,0);

        vector<int> counter(n,0);


        for(int i=0;i<n;i++){
            st.insert({1LL*0,i});
        }

        for(auto& meeting:meetings){
            pq.push({meeting[0],meeting[1]-meeting[0]});
        }

        while(!pq.empty()){
            auto p=pq.top();

            pq.pop();

            int startTime=p.first;
            int duration=p.second;

            bool flag=false;

            for(int i=0;i<n;i++){
                if(rooms[i]<=startTime){
                    flag=true;

                    st.erase({rooms[i],i});

                    long long temp=max(rooms[i],1LL*startTime)+duration;

                    st.insert({temp,i});

                    rooms[i]=temp;
                    counter[i]++;

                    break;
                }
            }
            if(!flag){
                auto it=*st.begin();

                st.erase(it);

                long long t2=max(it.first,1LL*startTime)+duration;

                st.insert({t2,it.second});

                rooms[it.second]=t2;
                counter[it.second]++;
            }
        }

        int ans=*max_element(counter.begin(),counter.end());

        for(int i=0;i<n;i++){
            if(counter[i]==ans) return i;
        }

        return -1;


    }
};