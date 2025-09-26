class Solution {
public:
    bool isValid(int n1,int n2,int n3){
        if(n1+n2>n3){
            return true;
        }
        return false;
    }
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){

                int lo=j+1;
                int hi=n-1;
                int maxCount=0;
                while(lo<=hi){
                    int mid=lo+(hi-lo)/2;

                    if(isValid(nums[i],nums[j],nums[mid])){
                        maxCount=max(maxCount,mid-j);
                        lo=mid+1;
                    }
                    else{
                        hi=mid-1;
                    }

                }
                ans+=maxCount;
            }
        }
        return ans;
    }
};   