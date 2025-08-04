class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n=fruits.size();
        int i=0;
        int j=1;
        int fn=fruits[0];
        int fi=0;
        int sn=-1;
        int si=-1;
        int count=1;
        while(j<n){
            if(fruits[j]==fn){
                fi=j;
            }
            else{
                if(sn==-1 || fruits[j]==sn){
                    sn=fruits[j];
                    si=j;
                }
                else{
                    count=max(count,j-i);
                    i=min(fi,si)+1;
                    if(i<n) fn=fruits[i];
                    fi=i;
                    si=-1;
                    sn=-1;
                    j=i;
                }
            }
            j++;
        }
        count=max(count,j-i);
        return count;
    }
};  