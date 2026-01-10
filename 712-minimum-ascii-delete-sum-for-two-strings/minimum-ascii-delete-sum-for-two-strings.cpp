class Solution {
public:
    int dp[1001][1001];
    int helper(string& s1,string&s2,int i,int j){
        if(i>=s1.size()){
            int temp=0;
            for(int k=j;k<s2.size();k++){
                temp+=s2[k];
            }
            return temp;
        }
        if(j>=s2.size()){
            int temp=0;
            for(int k=i;k<s1.size();k++){
                temp+=s1[k];
            }
            return temp;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        if(s1[i]==s2[j]) return helper(s1,s2,i+1,j+1);
        int op1=s1[i]+helper(s1,s2,i+1,j);
        int op2=s2[j]+helper(s1,s2,i,j+1);
        return dp[i][j]=min(op1,op2);
    }
    int minimumDeleteSum(string s1, string s2) {
        memset(dp,-1,sizeof(dp));
        int ans=helper(s1,s2,0,0);
        return ans;
    }
};