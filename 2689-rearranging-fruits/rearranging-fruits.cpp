class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        unordered_map<int,int> mp;
        int minEle=INT_MAX;
        for(int &x:basket1){
            mp[x]++;
            minEle=min(minEle,x);
        }   
        for(int &x:basket2){
            mp[x]--;
            minEle=min(minEle,x);
        }
        vector<int> finalList;
        for(auto& x:mp){
            int number=x.first;
            int count=x.second;
            if(count%2!=0) return -1;
            for(int c=1;c<=abs(count/2);c++){
                finalList.push_back(number);
            }

        }
        sort(finalList.begin(),finalList.end());
        long long ans=0;
        for(int i=0;i<finalList.size()/2;i++){
            ans+=min(finalList[i],minEle*2);   // minEle*2 is the catch woh isliye use kiya kyuki minEle ko use krke swap macha lo 
        }
        return ans;
    }
};