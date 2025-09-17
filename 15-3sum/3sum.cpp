class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        int k=n-1;
        set<vector<int>> res;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n-2;i++){
            int j=i+1;
            k=n-1;
            while(j<k)
            {
                int val=nums[i]+nums[j]+nums[k];
                if(val==0){
                    res.insert({nums[i],nums[j],nums[k]});
                    j++;
                    k--;
                }
                else if(val<0){
                    j++;
                }
                else{
                    k--;
                }
                
            }
        }
        vector<vector<int>> ans;
        for(auto& v:res){
            ans.push_back(v);
        }
        return ans;

    }
};