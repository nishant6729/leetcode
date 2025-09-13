class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int currRem = 0;
        int total = 0;          // changed: keep overall net
        int n = gas.size();
        int ans = 0;

        for (int i = 0; i < n; i++) {
            int temp = gas[i] - cost[i];
            currRem += temp;
            total += temp;      // minimal add: accumulate overall net

            if (currRem < 0) {
                currRem = 0;
                ans = i + 1;
            }
        }

        if (total >= 0) return ans % n; // overall feasibility check
        return -1;
    }
};
