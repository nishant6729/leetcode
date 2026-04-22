class Solution {
public:
    bool helper(string w1,string w2){

        if(w1.size()!=w2.size()) return false;
        int diff=0;

        for(int i=0;i<w1.size();i++){
            if(w1[i]!=w2[i]){
                diff++;
            }

            if(diff>2) return false;
        }

        return true;
    }
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {

        vector<string> ans;

        int n=queries.size();

        int m=dictionary.size();

        for(int i=0;i<n;i++){
            auto curr=queries[i];
            for(int j=0;j<m;j++){
                bool isPossible=helper(curr,dictionary[j]);

                if(isPossible){
                    ans.push_back(curr);
                    break;
                }
            }
        }

        return ans;
    }
};