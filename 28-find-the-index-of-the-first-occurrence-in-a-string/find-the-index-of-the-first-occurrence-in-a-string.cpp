class Solution {
public:
    int strStr(string haystack, string needle) {
        int i=0;
        int j=0;
        int n=haystack.size();
        if(haystack.size()<needle.size()){
            return -1;
        }
        while(i<n){
            if(haystack[i]!=needle[j]) i++;
            else{
                int startIdx=i;
                while((i<n && j<needle.size()) && haystack[i]==needle[j]){
                    i++;
                    j++;
                }
                if(j==needle.size()){
                    return startIdx;
                }
                else{
                    i=startIdx+1;
                    j=0;
                }
            }
            
        }
        return -1;
    }
};