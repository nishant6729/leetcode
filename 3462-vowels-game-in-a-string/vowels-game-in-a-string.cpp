class Solution {
public:
    bool doesAliceWin(string s) {
        int n=s.size();
        set<char> st;
        st.insert('a');st.insert('e');st.insert('i');st.insert('o');st.insert('u');
        int count=0;
        vector<int> prefix(n);
        int idx=0;
        for(auto c:s){
            if(st.find(c)!=st.end()){
                count++;
            }
            prefix[idx]=count;
            idx++;
        }
        bool flag=true;  // for alice turn
        int si=0;
        int vowels=0;
        while(si<n){
            int j=n-1;
            if(flag){
                while(j>=si){
                    if((prefix[j]-vowels)%2!=0){
                        vowels+=prefix[j];
                        flag=false;
                        si=j+1;
                        break;
                    }
                    j--;
                }
                if(flag!=false) return false;
            }
            else{
                while(j>=si){
                    if((prefix[j]-vowels)%2==0){
                        vowels+=prefix[j];
                        flag=true;
                        si=j+1;
                        break;
                    }
                    j--;
                }
                if(flag!=true) return true;
            }
        }
        if(flag) return false;
        else return true;
    }
};