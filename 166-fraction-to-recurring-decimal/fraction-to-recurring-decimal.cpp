class Solution {
public:
    string ans="";                     // ans is a member; we reset it at start of fractionToDecimal
    long long dn;
    unordered_map<long long,int> mp;

    void helper(long long n){
        if(n==0) return;
        if(mp.find(n)!=mp.end()){
            int idx = mp[n];
            ans.insert(idx, 1, '(');
            int curr = ans.size();
            ans.insert(curr, 1, ')');
            return;
        } else {
            long long temp = n;
            long long decimal = n / dn;    // using long long ensures no overflow
            mp[temp] = ans.size();
            ans += to_string(decimal);

            helper((n % dn) * 10);
        }
    }

    string fractionToDecimal(int numerator, int denominator) {
        ans.clear();                    // <--- FIX: ensure ans empty for each call (minimal safety)
        mp.clear();                     // <--- FIX: clear map as well

        bool flag = false;
        if(denominator < 0 || numerator < 0) flag = true;
        if(denominator < 0 && numerator < 0) flag = false;

        // convert to long long BEFORE taking abs to avoid overflow for INT_MIN
        long long nn = llabs((long long)numerator);
        dn = llabs((long long)denominator);

        long long first = nn / dn;      // <--- FIX: use long long (was int) to avoid overflow
        if(first == 0 && nn % dn == 0) return "0";

        string temp = to_string(first);
        if(flag){
            temp.insert(0, 1, '-');
        }

        // NOTE: removed the previous double-hyphen cleanup because it was incorrect
        // (it could remove a valid '-' or corrupt the string). There's never a case
        // where temp legitimately starts with "--" after the logic above.

        if(nn % dn == 0) return temp;
        ans += temp;
        ans.push_back('.');             // clearer than ans += temp + '.';
        helper((nn % dn) * 10);
        return ans;
    }
};
