class Solution {
public:
    string minWindow(string s, string t) {
        if(t.size()>s.size()) return "";
        unordered_map<char,int> mp;

        for(auto ch:t){
            mp[ch]++;
        }
        int i=0; // start pos
        int j=0; // sbke pass jaega check krne ke liye

        int minWindowSize=INT_MAX;
        int reqCount=t.size();

        int startI=0;  // substr finally bnane ke liye
        while(j<s.size()){
            char c=s[j];
            if(mp[c]>0){
                reqCount--;
            }   
            mp[c]--;
            while(reqCount==0){  // window shrink
                int currWindowSize=j-i+1;

                if(currWindowSize<minWindowSize){
                    minWindowSize=currWindowSize;
                    startI=i;
                }
                // shrinking ki baari

                mp[s[i]]++;
                if(mp[s[i]]>0) reqCount++;
                i++;
            }
            j++;
        }
        return minWindowSize==INT_MAX ?"":s.substr(startI,minWindowSize);
    }
};