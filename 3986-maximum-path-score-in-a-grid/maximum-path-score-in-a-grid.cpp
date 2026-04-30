class Solution {
public:
    int m, n;
    vector<vector<vector<int>>> dp;

    int helper(int i, int j, vector<vector<int>>& grid, int k) {
        if (i >= m || j >= n) return INT_MIN;

        int cost = (grid[i][j] != 0);
        int score = grid[i][j];

        if (cost > k) return INT_MIN;

        if (i == m - 1 && j == n - 1) {
            return score;
        }

        if (dp[i][j][k] != -1) return dp[i][j][k];

        int down = helper(i + 1, j, grid, k - cost);
        int right = helper(i, j + 1, grid, k - cost);

        int res = INT_MIN;

        if (down != INT_MIN) res = max(res, down + score);
        if (right != INT_MIN) res = max(res, right + score);

        return dp[i][j][k] = res;
    }

    int maxPathScore(vector<vector<int>>& grid, int k) {
        m = grid.size();
        n = grid[0].size();

        // 🔥 cap k (important)
        k = min(k, m + n);

        dp.assign(m, vector<vector<int>>(n, vector<int>(k + 1, -1)));

        int ans = helper(0, 0, grid, k);

        return (ans == INT_MIN) ? -1 : ans;
    }
};