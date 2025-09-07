class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> ans;
        int temp=n;
        n=n/2;
        if(temp%2==0){
            for(int i=-n;i<=n;i++){
                if(i==0) continue;
                ans.push_back(i);
            }
        }
        else{
            for(int i=-n;i<=n;i++){
                ans.push_back(i);
            }
        }
        return ans;
    }
};