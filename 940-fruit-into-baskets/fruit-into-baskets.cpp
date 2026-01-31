class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n1=-1;
        int n2=-1;

        int eidx1=-1;
        int eidx2=-1;

        int n=fruits.size();

        int i=0;

        int ans=0;
        for(int j=0;j<n;j++){
            if(n1==-1 && n2==-1){
                n1=fruits[j];
                eidx1=j;
            }
            else{
                if(fruits[j]==n1 || fruits[j]==n2){
                    if(fruits[j]==n1){
                        eidx1=j;
                    }
                    else{
                        eidx2=j;
                    }
                }
                else if(n1==-1 || n2==-1){
                    if(n1==-1){
                        n1=fruits[j];
                        eidx1=j;
                    }
                    else{
                        n2=fruits[j];
                        eidx2=j;
                    }
                }
                else{
                    ans=max(ans,j-i);

                    i=min(eidx1,eidx2)+1;

                    if(eidx1<eidx2){
                        n1=fruits[j];
                        eidx1=j;
                    }   
                    else{
                        n2=fruits[j];
                        eidx2=j;
                    }
                }

            }
        }
        ans=max(ans,n-i);
        return ans;
    }
};