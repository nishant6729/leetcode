class Solution {
public:
    long long solve(int l,int r){
        long long L=1;
        long long R=1;
        long long s=1;
        long long steps=0;
        while(L<=r){
            R=4*L-1;

            long long start=max(L,(long long)l);
            long long end=min((long long)r,R);
            if(start<=end){
                steps+=(end-start+1)*s;
            }
            L*=4;
            s++;
        }
        return (steps+1)/2;
    }
    long long minOperations(vector<vector<int>>& queries) {
        long long ans=0;
        for(auto q:queries){
            ans+=solve(q[0],q[1]);
        }
        return ans;
    }
};