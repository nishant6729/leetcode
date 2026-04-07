class Solution {
public:
    void computeLPS(string s,vector<int>& LPS){
        int len=0;

        int i=1;

        LPS[0]=0;

        while(i<s.size()){
            if(s[i]==s[len]){
                len++;
                LPS[i]=len;
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
    }
    string shortestPalindrome(string s) {
        // Smjhne wali baat hai ki yeh KMP algo or LPS ki concept se easily solve hoga


        string rev=s;

        reverse(rev.begin(),rev.end());

        string temp=s+'-'+rev;


        vector<int> LPS(temp.size(),0);

        computeLPS(temp,LPS);

        string culprit=rev.substr(0,s.size()-LPS[temp.size()-1]);

        string ans=culprit+s;

        return ans;
    }
};