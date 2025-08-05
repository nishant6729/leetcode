class Solution {
public:
    int helper(int n){
        if(n==0) return 1;
        if(n==1) return 10;
        int multi=1;
        int temp=8;
        for(int i=1;i<=n;i++){
            if(i==1 || i==2){
                multi*=9;
            }
            else{
                multi*=temp;
                temp--;
            }
        }
        return multi+helper(n-1);

    }
    int countNumbersWithUniqueDigits(int n) {
        int ans=helper(n);
        return ans;
    }
};