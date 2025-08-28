class Solution {
public:
    int helper(int n){ // give sum of square of the number
        int sumOfSquares=0;
        while(n>0){
            int digit=n%10;

            sumOfSquares+=digit*digit;

            n/=10;

        }
        return sumOfSquares;

    }
    bool isHappy(int n) {
        // based on cycle detection 
        // if cycle is detected on n=1 then true 
        // if cycle is detected in n!=1 then false
        int slow=n;
        int fast=helper(n);

        while(slow!=fast){
            slow=helper(slow);
            fast=helper(helper(fast));

        }
        return slow==1;
        
    }
};