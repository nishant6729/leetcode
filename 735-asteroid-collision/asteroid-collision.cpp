class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        // simple socho singe traversal me positive ko stack me dalo or negative ke through nikalo

        stack<int> st;

        vector<int> ans;

        for(int i=0;i<asteroids.size();i++){
            if(asteroids[i]>0){
                st.push(asteroids[i]);  // hum to right me chle
            }

            else{
                while(!st.empty() && (st.top()>0) && st.top()<abs(asteroids[i])){ // mere dushman + chote log ko maro
                    st.pop();
                }

                if(!st.empty() && st.top()==abs(asteroids[i])){ // marta hua aaya or mera bhai same value wala mila toh me khud bhi mra isliye woh pop and agli condition me else if kyuki ab me push nhi ho skta kyuki me bhi mr gya na 
                    st.pop();
                }

                else if(st.empty() || st.top()<0){ // ya toh koi bcha nhi ya meri jaati wale log hai yani me bcha rhuga akhir tk kyuki aane wale ya toh meri jaati ke honge ya agr dusri jaaati ke honge toh dusri side jaenge
                    st.push(asteroids[i]);
                }           
            }
        }

        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }

        reverse(ans.begin(),ans.end());
        return ans;
    }
};