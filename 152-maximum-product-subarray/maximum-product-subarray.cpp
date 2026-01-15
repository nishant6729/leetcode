class Solution {
public:
    int maxProduct(vector<int>& nums) {
       // Better than modified Kadane

       int pre=1;
       int suff=1;
       int n=nums.size();
        int ans=INT_MIN;
       for(int i=0;i<nums.size();i++){
          

           if(pre==0) pre=1;
           if(suff==0) suff=1;
            pre*=nums[i];
           suff*=nums[n-i-1];
            

            ans=max(ans,max(pre,suff));
       } 

       return ans;
    }
};