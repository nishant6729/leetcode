class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        long long sum = 0;
        for (int x : nums) sum += x;
        int rem = (int)(sum % k);
        return rem; // if rem==0 returns 0, otherwise need rem operations
    }
};
