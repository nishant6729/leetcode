class Solution {
public:
    vector<vector<int>> generate(int n) {
        vector<vector<int>> ans(n);
        ans[0]={1};
        if(n>1) ans[1]={1,1};
        for(int i=3;i<=n;i++){
            vector<int> temp(i);
            temp[0]=1;
            temp[i-1]=1;
            vector<int> v;
            v=ans[i-2];
            int k=0;
            int j=1;
            int ptr=1;
            while(j<v.size()){
                temp[ptr]=v[k]+v[j];
                ptr++;
                k++;
                j++;
            }
            ans[i-1]=temp;
        }
        return ans;
    }
};