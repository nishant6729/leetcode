class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        int n=nums.size();
        vector<int> pre(n);
        vector<int> suff(n);
        pre[0]=nums[0];
        suff[n-1]=nums[n-1];
        for(int i=1;i<n;i++){
            pre[i]=nums[i]+pre[i-1];
        }
        for(int i=n-2;i>=0;i--){
            suff[i]=nums[i]+suff[i+1];
        }
        int count=0;
        for(int i=0;i<n;i++){
            if(pre[i]==suff[i] && nums[i]==0){
                count+=2;
            }
            else if(abs(pre[i]-suff[i])==1 && nums[i]==0){
                count+=1;
            }
        }
        return count;
    }
};