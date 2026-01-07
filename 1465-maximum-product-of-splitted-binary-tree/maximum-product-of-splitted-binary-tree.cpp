class Solution {
public:
    unordered_map<TreeNode*, long long> sub;
    long long total = 0, ans = 0;
    const int MOD = 1e9+7;

    long long dfs(TreeNode* root){
        if(!root) return 0;
        long long sum = root->val + dfs(root->left) + dfs(root->right);
        sub[root] = sum;
        return sum;
    }

    int maxProduct(TreeNode* root) {
        total = dfs(root);

        queue<TreeNode*> qu;
        qu.push(root);

        while(!qu.empty()){
            auto it = qu.front(); qu.pop();

            if(it->left){
                long long s = sub[it->left];
                ans = max(ans, s * (total - s));
                qu.push(it->left);
            }
            if(it->right){
                long long s = sub[it->right];
                ans = max(ans, s * (total - s));
                qu.push(it->right);
            }
        }
        return ans % MOD;
    }
};
