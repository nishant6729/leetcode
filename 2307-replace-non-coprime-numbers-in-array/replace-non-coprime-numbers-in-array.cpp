class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        stack<long long> st;
        for(int i=0;i<nums.size();i++){
            long long curr=nums[i];

            while(!st.empty()){
                long long top=st.top();
                long long g=gcd(top,curr);
                if(g==1) break;
                st.pop();

                curr = lcm(top,curr);
            }
            st.push(curr);
        }
        vector<int> ans;
        while(!st.empty()){
            ans.push_back((int)st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};