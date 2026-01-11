class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        vector<vector<pair<int,int>> > dp(m,vector<pair<int,int>>(n,{0,0}));


        for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                if(matrix[i][j]=='0'){
                    dp[i][j]={0,0};
                }
                else{
                    if(i+1<m){
                        dp[i][j].second=dp[i+1][j].second+1;
                    }
                    else{
                        dp[i][j].second=1;
                    }

                    if(j+1<n){
                        dp[i][j].first=dp[i][j+1].first+1;
                    }
                    else{
                        dp[i][j].first=1;
                    }
                }
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                cout<<dp[i][j].first<<" "<<dp[i][j].second<<"//";
            }
            cout<<endl;
        }
        int ans=0;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int width = dp[i][j].first;

                for(int k=i; k<m && dp[k][j].second > 0; k++){
                    width = min(width, dp[k][j].first);
                    int height = k - i + 1;
                    ans = max(ans, width * height);
                }
            }
        }

        return ans;

    }
};