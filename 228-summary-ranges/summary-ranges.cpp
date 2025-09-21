class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int i=0;
        int j=1;
        vector<string> ans;
        while(i<nums.size()){
            if(j==nums.size()){
                if(j-1==i){
                    ans.push_back(to_string(nums[i]));
                    i=j;
                    j=i+1;
                }
                else{
                    string temp=to_string(nums[i])+"->"+to_string(nums[j-1]);
                    ans.push_back(temp);
                    i=j;
                    j=i+1;
                }
                continue;
            }
            while(j<nums.size() && nums[j] == nums[j-1] + 1){
                j++;
            }
            if(j-1==i){
                ans.push_back(to_string(nums[i]));
                i=j;
                j=i+1;
            }
            else{
                string temp=to_string(nums[i])+"->"+to_string(nums[j-1]);
                ans.push_back(temp);
                i=j;
                j=i+1;
            }
        }   
        return ans;
    }
};