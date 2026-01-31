class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int found=-1;
        char ans='-1';
        for(auto& c:letters){
            if(c>target && found==-1){
                ans=c;
                found=1;
            }
            else if(c>target && found!=-1){
                if(c<ans){
                    ans=c;
                }
            }
        }
        if(found==-1) return letters[0];
        else return ans;
    }
};