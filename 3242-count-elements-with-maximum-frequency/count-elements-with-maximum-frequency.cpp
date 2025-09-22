class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        int maxFreq=INT_MIN;
        unordered_map<int,int> mp;
        for(auto& i:nums){
            mp[i]++;
        }
        for(auto& p:mp){
            maxFreq=max(maxFreq,p.second);
        }
        int count=0;
        for(auto& p:mp){
            if(p.second==maxFreq) count++;
        }
        return count*maxFreq;
    }
};