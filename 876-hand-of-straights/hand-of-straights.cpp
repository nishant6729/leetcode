class Solution {
public:
    typedef pair<int,int> P;
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        
        if(hand.size()%groupSize!=0) return false;

        unordered_map<int,int> mp;

        for(auto& i:hand){
            mp[i]++;
        }

        priority_queue<P,vector<P>,greater<P>> pq;  // {number,rem frequency}
 
        for(auto& p:mp){
            pq.push({p.first,p.second}); 
        }

        while(!pq.empty()){
            vector<pair<int,int>> temp;  // store krne ke liye temporary

            int pastNumber=-1;
            for(int i=0;i<groupSize;i++){
                auto it=pq.top();

                int number=it.first;
                int freq=it.second;

                if(freq-1>0){
                    temp.push_back({number,freq-1});
                }

                if(pastNumber!=-1 && number-pastNumber!=1) return false;

                pastNumber=number;
                pq.pop();
            } 

            for(auto& ele:temp){
                pq.push(ele);
            }

            
        }
        return true;
    }
};