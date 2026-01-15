class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        sort(hBars.begin(),hBars.end());

        sort(vBars.begin(),vBars.end());


        int c1=1;
        int c1Max=1;
        int c2=1;
        int c2Max=1;
        for(int i=1;i<hBars.size();i++){
            if(hBars[i]-hBars[i-1]==1){
                c1++;
                c1Max=max(c1Max,c1);
            }
            else{
                c1=1;
                c1Max=max(c1Max,c1);
            }
        }

        for(int i=1;i<vBars.size();i++){
            if(vBars[i]-vBars[i-1]==1){
                c2++;
                c2Max=max(c2Max,c2);
            }
            else{
                c2=1;
                c2Max=max(c2Max,c2);
            }
        }

        int width=min(c1Max,c2Max)+1;
        return width*width;

    }
};