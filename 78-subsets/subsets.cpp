class Solution {
public:
    vector<vector<int>> ans;

    void helper(vector<int>& nums,int idx,vector<int>& curr){

        if(idx==nums.size()){
            ans.push_back(curr);
            return;
        }
        ans.push_back(curr);

        for(int i=idx;i<nums.size();i++){
            curr.push_back(nums[i]);

            helper(nums,i+1,curr);

            curr.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> curr;
        helper(nums,0,curr);


        return ans;
    }
};