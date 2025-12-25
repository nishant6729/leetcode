class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        sort(happiness.begin(),happiness.end());
        long long sum=0;
        int n=happiness.size();
        int currTime=0;
        int currIdx=n-1;
        while(k--){
            sum+=max(1LL*0,1LL* happiness[currIdx]-currTime*1);
            currTime++;
            currIdx--;
        }
        return sum;
    }
};