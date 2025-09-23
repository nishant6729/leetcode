class Solution {
public:
    string helper(string& s){
        if(s.empty()) return "";
        bool containsDigit=false;
        for(auto& c:s){
            if(isdigit(c)){
                containsDigit=true;
                break;
            } 
        }
        if(!containsDigit) return s;
        string ans="";
        for(int i=0;i<s.size();i++){
            char c=s[i];
            if(isalpha((unsigned char)c)){
                ans+=c;
            }
            else if(isdigit(c)){
                int curr=i;
                int j=curr+1;
                while(s[j]!='['){
                    j++;
                }
                string numString=s.substr(curr,j-curr);
                int freq=stoi(numString);
                curr=j+1;
                j=curr+1;
                int ptr=1;
                
                while(j<s.size() && ptr>0){
                   
                    if(s[j]=='[') ptr++;
                    if(s[j]==']') ptr--;
                    if(ptr==0) break;
                    j++;
                }
                string newStr=s.substr(curr,j-curr);

                for(int k=0;k<freq;k++){
                    ans+=helper(newStr);
                }
                i=j;
            }
        }
        return ans;
    }
    string decodeString(string s) {
        string ans=helper(s);
        return ans;
    }
};