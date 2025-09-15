class Solution {
public:
    string reverseWords(string s) {
        vector<string> words;
        int i=0;
        int j=s.size()-1;
        int n=s.size();
        while(i<n && s[i]==' '){
            i++;
        }
        while(j>=0 && s[j]==' '){
            j--;
        }
        int k=i;
        while(k<=j){
            while(k<=j && s[k]!=' '){
                k++;
            }
            words.push_back(s.substr(i,k-i));
            while(k<=j && s[k]==' '){
                k++;
            }
            i=k;

        }
        string ans="";
        for(int i=words.size()-1;i>=0;i--){
            ans+=words[i];
            if(i!=0){
                ans+=" ";
            }
            
        }
        return ans;
    }
};