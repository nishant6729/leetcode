class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char,int> mp;
        mp['M']=1000;mp['D']=500;mp['C']=100;mp['L']=50;
        mp['X']=10;mp['V']=5;mp['I']=1;
        int n=0;
        for(int i=0;i<s.size();i++){
            char c=s[i];
            if(i+1<s.size() && mp[s[i+1]]>mp[c]){
                n+=mp[s[i+1]]-mp[c];
                i++;
            }
            else n+=mp[c];
        }
        return n;
    }
};