class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n=nums.size();
        long long ans=0;
        for(int i=0;i<n;i++){
            int maxEle=nums[i];
            int minEle=nums[i];

            for(int j=i+1;j<n;j++){
                maxEle=max(maxEle,nums[j]);
                minEle=min(minEle,nums[j]);

                ans+=1LL*maxEle-minEle;
            }
        }

        return ans;
    }
};