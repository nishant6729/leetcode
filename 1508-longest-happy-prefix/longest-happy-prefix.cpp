class Solution {
public:
    string longestPrefix(string s) {
        // Sidha Sidha LPS ka array bnao for s string 

        // Ab LPS me dhyan rkhna sirf ek case jisme matching nhi ho rhi hai s[i]!=s[len]

        vector<int> LPS(s.size(),0);

        LPS[0]=0;

        int len=0;
        int i=1;

        while(i<s.size()){
            if(s[i]==s[len]){  // bdiya chiz business bdao felao systum
                LPS[i]=len+1;
                len++;
                i++;
            }
            else{
                if(len>0){
                    len=LPS[len-1];

                }
                else{
                    LPS[i]=0;
                    i++;
                }
            }
        }

        if(LPS[s.size()-1]==0) return "";
        else return s.substr(0,LPS[s.size()-1]);

    }
};