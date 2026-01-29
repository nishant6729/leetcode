class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;

        int n=num.size();

        for(int i=0;i<n;i++){
            while(!st.empty() && (k>0 &&( st.top()-'0'>num[i]-'0'))){  // higher level pe chote se chota int lena shi rhega 
                st.pop();
                k--;
            }

            st.push(num[i]);  

        }

        if(k>0){  // abhi bhi req size se bde hai hum 
            while(k>0){
                st.pop();
                k--;
            }
        }

        string result="";
        while(!st.empty()){
            result+=st.top();
            st.pop();
        }
        while(result.size()>0 && result.back()=='0'){  // leading zeroes in final ans
            result.pop_back();
        }

        if(result.size()==0) return "0";

        reverse(result.begin(),result.end());

        return result;

    }
};