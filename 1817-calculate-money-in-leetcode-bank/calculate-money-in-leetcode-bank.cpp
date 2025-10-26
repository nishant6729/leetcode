class Solution {
public:
    int totalMoney(int n) {
        int ans=0;
        int loop=n/7;
        int dayCount=0;
        if(n%7!=0) loop++;
        for(int i=1;i<=loop;i++){
            int startVal=i;
            for(int j=1;j<=7 && dayCount<n;j++){
                ans+=startVal;
                startVal++;
                dayCount++;
            }
        }
        return ans;
    }
}; 