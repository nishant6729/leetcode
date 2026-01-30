class Solution {
public:
    typedef pair<long long,string> P;
    const long long INF=1e10;
    string srcStr;
    string targetStr;

    unordered_map<string,long long> dijstraMemo;
    unordered_map<string,vector<pair<string,long long>> >mp;   // src ->{dst,cost} ke liye adj map 

    
    set<int> validLengths; // diff length jo original vector ki string ki hai yhi length valid hogi sirf

    vector<long long> dpMemo;

    long long dijstra(string start,string end){
        
        string key=start+"->"+end;

        if(dijstraMemo.count(key)){
            return  dijstraMemo[key];
        }
        unordered_map<string,long long> dist;  //source to string ka cost stored
        priority_queue<P,vector<P>,greater<P>> pq;



        pq.push({0,start});

        dist[start]=0;

        while(!pq.empty()){

            auto it=pq.top();

            pq.pop();

            long long currCost=it.first;
            string currNode=it.second;

            if(currNode==end){
                return dijstraMemo[key]=currCost;
            }

            for(auto& p:mp[currNode]){
                string adjNode=p.first;
                long long thatDist=p.second;
                
                if(!dist.count(adjNode) || currCost+thatDist<dist[adjNode]){
                    dist[adjNode]=currCost+thatDist;

                    pq.push({currCost+thatDist,adjNode});
                    
                }
            }   
        }
         long long  finalCost = dist.count(end) ? dist[end] : INF;

         return dijstraMemo[key]=finalCost;
    }

    long long solve(int idx){

        if(idx>=srcStr.size()) return 0;

        if(dpMemo[idx]!=-1) return dpMemo[idx];

        long long minCost=INF;        

        if(srcStr[idx]==targetStr[idx]){  // possibility 1 
            minCost=min(minCost,solve(idx+1)); 
        }

        for(auto& len:validLengths){
            if(idx+len>srcStr.size()) break;

            string start=srcStr.substr(idx,len);
            string end=targetStr.substr(idx,len);
            if (start == end) {
                minCost = min(minCost, solve(idx + len));
                continue;
            }

            if(!mp.count(start)){  // itni len ka mamla ke liye ko direction nhi hai 
                continue;     
            }

            long long minPathCost=dijstra(start,end);

            if(minPathCost==INF) continue;  // is len ke liye path nhi hai acha
            minCost=min(minCost,minPathCost+solve(idx+len));  // overlapping wala nhi lena isliye 



        }

        return dpMemo[idx]=minCost;
    }
    long long minimumCost(string source, string target, vector<string>& original, vector<string>& changed, vector<int>& cost) {
        // Bahut dhasu level ka question DP aa gya with graph dijshtra or dijshtra me bhi memo lgega 
        // isliye question high order thinking chahta hai 
        if (source.size() != target.size()) return -1;

        srcStr=source;
        targetStr=target;

        dpMemo.assign(1001,-1);

        for(int i=0;i<original.size();i++){
            mp[original[i]].push_back({changed[i],cost[i]});
        }

        for(auto& s:original){
            validLengths.insert(s.size());
        }

        long long result=solve(0);

        return result==INF?-1:result;
    }
};