/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int ans;
    int helper(TreeNode* root){
        if(!root) return 0;

        int leftHalf=max(0,helper(root->left));

        int rightHalf=max(0,helper(root->right));

        ans=max(ans,root->val+(leftHalf+rightHalf));

        return root->val+max(leftHalf,rightHalf);

    }
    int maxPathSum(TreeNode* root) {
        ans=INT_MIN;

        helper(root);

        return ans;
    }
};