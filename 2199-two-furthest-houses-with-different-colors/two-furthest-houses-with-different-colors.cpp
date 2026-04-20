class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int i=0;

        int n=colors.size();

        int j=n-1;

        int ans=0;


        while(i<=j && colors[i]==colors[j]){
            j--;
        }

        ans=max(ans,j-i);

        j=n-1;

        while(i<=j && colors[i]==colors[j]){
            i++;
        }

        ans=max(ans,j-i);

        return ans;
    }
};