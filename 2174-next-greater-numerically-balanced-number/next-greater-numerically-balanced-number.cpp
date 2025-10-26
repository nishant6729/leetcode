class Solution {
public:
    bool helper(int n){
        vector<int> freq(10,0);
        int temp=n;

        while(temp>0){
            freq[temp%10]++;
            temp/=10;
        }
        for(int i=0;i<10;i++){
            if(freq[i]!=0){
                if(freq[i]!=i){
                    return false;
                }
            }
        }
        return true;
        
        
    }

    int nextBeautifulNumber(int n) {
        n++;
        while(!helper(n)){
            n++;
    
        }
        return n;
    }
};