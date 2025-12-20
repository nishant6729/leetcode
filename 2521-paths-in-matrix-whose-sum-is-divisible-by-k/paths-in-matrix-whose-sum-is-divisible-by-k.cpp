class Solution {
public:
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        const int MOD = 1e9 + 7;
        int m = grid.size(), n = grid[0].size();

        // dp[j][r] = ways to reach previous row at column j with remainder r
        vector<vector<int>> dp(n, vector<int>(k, 0));

        for(int i = 0; i < m; i++) {
            vector<vector<int>> newdp(n, vector<int>(k, 0));
            for(int j = 0; j < n; j++) {
                int val = grid[i][j] % k;
                if(i == 0 && j == 0) {
                    // start cell: exactly one path with remainder = grid[0][0] % k
                    newdp[0][val] = 1;
                    continue;
                }

                for(int r = 0; r < k; r++) {
                    int prev = (r - val + k) % k;
                    long long ways = 0;
                    if(i > 0) ways += dp[j][prev];          // from top (previous row)
                    if(j > 0) ways += newdp[j - 1][prev];   // from left (current row)
                    if(ways) newdp[j][r] = (newdp[j][r] + (int)(ways % MOD)) % MOD;
                }
            }
            dp = move(newdp);
        }

        return dp[n - 1][0];
    }
};
