class Solution {
public:
    string sortVowels(string s) {
        int n=s.size();
        set<char> st;
        st.insert('a');st.insert('e');st.insert('i');st.insert('o');st.insert('u');
        st.insert('A');st.insert('E');st.insert('I');st.insert('O');st.insert('U');
        vector<int> idx;
        vector<char> letters;
        for(int i=0;i<n;i++){
            if(st.find(s[i])!=st.end()){
                letters.push_back(s[i]);
                idx.push_back(i);
            }
        }
        sort(letters.begin(),letters.end());
        for(int i=0;i<letters.size();i++){
            s[idx[i]]=letters[i];
        }
        return s;
    }
};