class Solution {
public:
    int maxSum = INT_MIN; // global max path sum

    int helper(TreeNode* root) {
        if (root == NULL) return 0;

        // Get left and right max path sum, ignore negative values
        int left = max(0, helper(root->left));
        int right = max(0, helper(root->right));

        // Update maxSum considering path through current node
        maxSum = max(maxSum, root->val + left + right);

        // Return max path sum going downward (one side only)
        return root->val + max(left, right);
    }

    int maxPathSum(TreeNode* root) {
        helper(root);
        return maxSum;
    }
};
