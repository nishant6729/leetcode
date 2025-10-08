class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        vector<int> ans;
        sort(potions.begin(),potions.end());
        int m=potions.size();
        for(int i=0;i<spells.size();i++){
            int spell=spells[i];
            double minReq=1.0*success/spell;
            
            int lo=0;
            int hi=potions.size()-1;
            int minIdx=INT_MAX;
            while(lo<=hi){
                int mid=lo+(hi-lo)/2;

                if(potions[mid]>=minReq){
                    minIdx=mid;
                    hi=mid-1;
                    
                }
                else{
                    lo=mid+1;
                }
                
            }

            if(minIdx==INT_MAX){
                ans.push_back(0);
            }
            else{
                ans.push_back(m-minIdx);
            }
            
        }
        return ans;
    }
};