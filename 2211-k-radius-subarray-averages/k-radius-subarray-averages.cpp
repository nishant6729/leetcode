class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int ki) {
        int n = nums.size();
        vector<int> ans(n);
        vector<long long> pre(n);   // <- changed to long long
        vector<long long> post(n);  // <- changed to long long

        int i = 0;
        int j = 0;
        long long sum = 0;
        while (j < n) {
            if (j - i < ki) {
                sum += nums[j];
                pre[j] = -1;
                j++;
            } else {
                pre[j] = sum;
                sum -= nums[i];
                i++;
                sum += nums[j];
                j++;
            }
        }

        i = n - 1;
        j = n - 1;
        sum = 0;
        while (j >= 0) {
            if (i - j < ki) {
                sum += nums[j];
                post[j] = -1;
                j--;
            } else {
                post[j] = sum;
                sum -= nums[i];
                i--;
                sum += nums[j];
                j--;
            }
        }

        for (int idx = 0; idx < n; idx++) {
            if (pre[idx] == -1 || post[idx] == -1) {
                ans[idx] = -1;
            } else {
                long long total = pre[idx] + post[idx] + nums[idx]; // use long long
                ans[idx] = int(total / (2LL * ki + 1LL));
            }
        }
        return ans;
    }
};
