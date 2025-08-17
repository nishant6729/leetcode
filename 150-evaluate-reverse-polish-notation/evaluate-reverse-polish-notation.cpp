class Solution {
public:
    int calc(int n1,int n2,string op){
        if(op=="+") return n1+n2;
        else if(op=="-")    return n1-n2;
        else if(op=="*")    return n1*n2;
        else return n1/n2;
    }
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(auto s:tokens){
            if(s=="+" || s=="-" || s=="*" || s=="/"){
                int n2=st.top();
                st.pop();
                int n1=st.top();
                st.pop();
                int temp=calc(n1,n2,s);
                st.push(temp);
            }
            else{
                int temp=stoi(s);
                st.push(temp);
            }
        }
        return st.top();
    }
};