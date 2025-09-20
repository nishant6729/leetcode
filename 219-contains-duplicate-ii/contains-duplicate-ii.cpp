class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        for(int i=0;i<nums.size();i++){
            if(mp.find(nums[i])==mp.end()){
                mp[nums[i]]=i;
            }
            else{
                int diff=i-mp[nums[i]];
                if(diff<=k) return true;
                mp[nums[i]]=i;
            }
        }
        return false;
    }
};