class Solution {
public:
    void parenthesis(string s,int op,int cp,int n,vector<string> &v){
       if(cp==n){
           v.push_back(s);
           return;
       }
       if(op<n) parenthesis(s+'(',op+1,cp,n,v);
       if(cp<op) parenthesis(s+')',op,cp+1,n,v);
    }

    vector<string> generateParenthesis(int n) {
        vector<string> v;
        parenthesis("",0,0,n,v);
        return v;
    }
};