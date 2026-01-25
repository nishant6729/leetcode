class Solution {
public:
    int t;

    vector<string> ans;

    void helper(int idx,string expression,long long total,long long last,string s){

        if(idx==s.size()){
            if(total==t){
                ans.push_back(expression);
            }

            return;
        }
        for(int i=idx;i<s.size();i++){
            if(i>idx && s[idx]=='0'){  // leading zero ka case single zero allowed but leading not therefore i>idx use kiya 
                    break;
            }
            string currExp=s.substr(idx,i-idx+1);

            long long currVal=stoll(currExp);

            if(idx==0){
                helper(i+1,currExp,currVal,currVal,s);
            }
            else{
                helper(i+1,expression+'+'+currExp,total+currVal,currVal,s);   // add wala case 

                helper(i+1,expression+'-'+currExp,total-currVal,-currVal,s);   // minus wala case 

                helper(i+1,expression+'*'+currExp,total-last+last*currVal,last*currVal,s);  // sbse imp multiply wala case 




            }


        }
    }
    vector<string> addOperators(string num, int target) {
        // Sara game operator precedence ka hai 
        // * has more priority than + and - 

        t=target;

        helper(0,"",0,0,num);

        return ans;
    }
};