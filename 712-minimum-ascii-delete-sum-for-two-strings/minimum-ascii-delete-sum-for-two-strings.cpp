class Solution {
public:
    
    int helper(string &s1,string &s2,int i,int j,vector<vector<int>>& dp){
         

        if(i>=s1.size()){
            int count=0;
            for(int k=j;k<s2.size();k++){
                count+=int(s2[k]);
            }
            return count;
        }
        if(j>=s2.size()){
            int count=0;
            for(int k=i;k<s1.size();k++){
                count+=int(s1[k]);
            }
            return count;
        }
       if(dp[i][j]!=-1) return dp[i][j];

        if(s1[i]==s2[j]){
            return dp[i][j]=helper(s1,s2,i+1,j+1,dp);
        }

        else{
            int case1=s1[i]+helper(s1,s2,i+1,j,dp);
            int case2=s2[j]+helper(s1,s2,i,j+1,dp);

            return dp[i][j]=min(case1,case2);
        }
    }
    int minimumDeleteSum(string s1, string s2) {

        vector<vector<int>> dp(s1.size(),vector<int>(s2.size(),-1));

        int ans=helper(s1,s2,0,0,dp);

        return ans;
    }
};