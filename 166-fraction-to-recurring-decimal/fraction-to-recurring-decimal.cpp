class Solution {
public:
    string ans="";
    long long dn;
    unordered_map<long long,int> mp;
    void helper(long long n){
        
        if(n==0) return;
        if(mp.find(n)!=mp.end()){
            int idx=mp[n];
            ans.insert(idx,1,'(');
            int curr=ans.size();
            ans.insert(curr,1,')');
            return;
        }
        else{
            long long temp=n;
            long long decimal=n/dn;
            mp[temp]=ans.size();
            ans+=to_string(decimal);

            
            helper((n%dn)*10);
            
        }

    }
    string fractionToDecimal(int numerator, int denominator) {
        ans.clear();
        mp.clear();
        bool flag=false;
        if(denominator<0 || numerator<0){
            flag=true;
        }
        if(denominator<0 && numerator<0){
            flag=false;
        }
        
        long long nn = llabs((long long)numerator);
        dn = llabs((long long)denominator);
        
        long long first=nn/dn;
        if(first==0 && nn%dn==0) return "0";
        string temp=to_string(first);
        if(flag){
            temp.insert(0,1,'-');
        }
        
        if(nn%dn==0) return temp;
        ans+=temp+'.';
        helper((nn%dn)*10);
        return ans;
    }
};