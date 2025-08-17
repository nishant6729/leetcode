class Solution {
public:
    double new21Game(int n, int k, int M) {
        vector<double> P(n+1,0.0);
        P[0]=1.0; //initially 0 point to hai hi na 

        double currProbSum= k>0 ? 1.0: 0.0; // suru me total sari probability ka sum

        for(int i=1;i<=n;i++){ // n se chota mamla chahiye isliye sbka nikal lete hai
            P[i]=currProbSum/M; // abhi ki probability nikal li 
            if(i<k){
                currProbSum+=P[i]; // jha tk ki prob Sum aage kaam aagega usko hi involve kro jo aage kaam nhi aaeaga like k or usse bde 
            }

            if(i-M>=0 && i-M<k){
                currProbSum-=P[i-M];
            }

        }
        return accumulate(P.begin()+k,P.end(),0.0);

    }
};