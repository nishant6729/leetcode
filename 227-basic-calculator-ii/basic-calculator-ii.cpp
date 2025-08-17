class Solution {
public:
    string number;
    
    int helper(int idx){
        int j=idx;
        while(j<number.size()  && isdigit(number[j])){
            j++;
            
        }
        int len=j-idx;
        string temp=number.substr(idx,len);
        int t1=stoi(temp);
        return t1;
    }
    int calc(int n1,int n2,char op){
        if(op=='+') return n1+n2;
        else if(op=='-') return n1-n2;
        else if(op=='*') return n1*n2;
        else return n1/n2;
    }
    int calculate(string s) {
        number=s;
        int n=s.size();
        stack<int> val;
        stack<char> op;
        int i=0;
        while(i<n){
            if(s[i]=='+' || s[i]=='-'){
                op.push(s[i]);
                i++;
                continue;
            }
            else if(s[i]=='*' || s[i]=='/'){
                int n1=val.top();
                val.pop();
                char opr=s[i];
                i++;
                while(s[i]==' ') i++;
                int n2=helper(i);
                
                int temp=calc(n1,n2,opr);
                val.push(temp);
                
                while(isdigit(s[i])){
                    i++;
                }
            }
            else if(s[i]==' ') i++;
            else{
                int n1=helper(i);
                val.push(n1);
                while(isdigit(s[i])){
                    i++;
                }
            }
        }
        stack<int> s1;
        stack<char> s2;
        while(!val.empty()){
            int temp=val.top();
            val.pop();
            s1.push(temp);
        }
        while(!op.empty()){
            char temp=op.top();
            op.pop();
            s2.push(temp);
        }
        while(!s1.empty() && !s2.empty()){
            int n1=s1.top();
            s1.pop();
            int n2=s1.top();
            s1.pop();
            char o=s2.top();
            s2.pop();
            int t=calc(n1,n2,o);
            s1.push(t);
        }
        return s1.top();
    
    }
};