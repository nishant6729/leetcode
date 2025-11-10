class Solution {
public:
    int minimumOneBitOperations(int n) {
        int g = n;
        int b = g;
        for (g >>= 1; g; g >>= 1) {
            b ^= g;
        }
        return b;
    }
};
