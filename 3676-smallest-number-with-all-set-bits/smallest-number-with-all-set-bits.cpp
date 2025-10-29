class Solution {
public:
    int smallestNumber(int n) {
        if(n<3) return 1;
        vector<int> temp(20);
        temp[0]=3;
        for(int i=1;i<20;i++){
            temp[i]=temp[i-1]+pow(2,i+1);
        }
        for(auto& i:temp){
            if(i>=n){
                return i;
            }
        }
        return -1;
    }
};