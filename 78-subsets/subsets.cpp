class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        
        // no of subsets 2^n

        // Logic Tabul ki tarah socho
        int n=nums.size();

        int total=1<<n;

        vector<vector<int>> ans;
        for(int sub=0;sub<total;sub++){
            vector<int> temp;
            for(int i=0;i<n;i++){

                if(sub &(1<<i)){
                    temp.push_back(nums[i]);
                }
            }

            ans.push_back(temp);
        }
        
        return ans;
    }
};