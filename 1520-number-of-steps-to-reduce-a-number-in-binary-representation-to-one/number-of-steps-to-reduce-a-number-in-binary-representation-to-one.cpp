class Solution {
public:
    int numSteps(string s) {
        int ans=0;

        while(s!="1"){


            if(s[s.size()-1]=='0'){ // even

                s.pop_back();
                ans++;

            }
            else{
                int idx=s.size()-1;

                while(idx>=0 && s[idx]=='1'){
                    s[idx]='0';
                    idx--;
                }

                if(idx<0) s='1'+s;
                else{
                    s[idx]='1';
                }
                
                ans++;
            }
        }

        return ans;
    }
};