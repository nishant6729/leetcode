class Solution {
public:
    int maxSum = INT_MIN;

    int helper(TreeNode* root) {
        if (root == NULL) return 0;

    
        int left = max(0, helper(root->left));
        int right = max(0, helper(root->right));


        maxSum = max(maxSum, root->val + left + right);


        return root->val + max(left, right);
    }

    int maxPathSum(TreeNode* root) {
        helper(root);
        return maxSum;
    }
};
