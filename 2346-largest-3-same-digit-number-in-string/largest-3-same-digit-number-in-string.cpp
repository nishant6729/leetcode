class Solution {
public:
    string largestGoodInteger(string num) {
        int i,j,k;
        int n=num.size();
        i=0;
        j=1;
        k=2;
        if(num.size()<3) return "";
        char c='!';
        while(k<n){
            if(num[i]==num[j] && num[j]==num[k]){
                if(c<num[i]){
                    c=num[i];
                }
                
            }
            i++;
            j++;
            k++;
        }
        string temp;
        if(c=='!') return "";
        else{
            temp+=c;
            temp+=c;
            temp+=c;
        }
        return temp;
    }
};