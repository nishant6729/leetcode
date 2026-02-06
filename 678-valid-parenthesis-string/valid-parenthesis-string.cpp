class Solution {
public:
    bool checkValidString(string s) {
        // can't go for recursion and DP Dp:-O(n^2) and recursion 3^N

        // Greedy use krte hai 

        int openMax=0;
        int openMin=0;   // range maintain krte hai kyuki single var se kaam nhi chlega 

        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                openMin++;
                openMax++;
            }
            else if(s[i]==')'){
                openMin=max(0,openMin-1);
                openMax--;
                if(openMax<0) return false;
            }
            else{
                openMin=max(0,openMin-1);  // zero se niche mt jane do
                openMax=openMax+1;

                if(openMax<0){
                    return false;
                }
            }
        }

        return openMin==0;
    }
};