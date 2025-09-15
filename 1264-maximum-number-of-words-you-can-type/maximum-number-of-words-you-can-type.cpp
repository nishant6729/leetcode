class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        unordered_set<char> broken;
        for(auto& c:brokenLetters){
            broken.insert(c);
        }
        int i=0;
        int j=0;
        int count=0;
        int n=text.size();
        while(j<n){
            bool flag=true;
            while(j<n && text[j]!=' '){
                if(broken.count(text[j])){
                    flag=false;
                }
                j++;    
            }
            if(flag){
                count++;
            }
            i=j+1;
            j=i;
        }
        return count;
    }
};