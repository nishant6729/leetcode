class Solution {
public:
    int hIndex(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int n=arr.size();
        int ans=0;
        for(int i=n-1;i>=0;i--){
            int temp=min(n-i,arr[i]);
            ans=max(ans,temp);
        }
        return ans;
    }
};