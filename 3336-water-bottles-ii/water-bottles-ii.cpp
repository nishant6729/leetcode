class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int emptyCount=numBottles;
        int ans=numBottles;
        int fillCount=0;
        while(emptyCount>=numExchange){
            fillCount+=1;
            emptyCount=emptyCount-numExchange;
            numExchange++;
            if(emptyCount<numExchange){
                emptyCount+=fillCount;
                ans+=fillCount;
                fillCount=0;
            }
            

        }
        return ans+fillCount;
    }
};