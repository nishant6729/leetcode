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
    int maxSum=INT_MIN;
    int helper(TreeNode* root){
        if(!root) return 0;
        int left=max(0,helper(root->left));  // avoid kro negative sum kyuki agar kch nhi liya toh waise bhi 0 sum hai hi humare pass kisi side ke path ka
        int right=max(0,helper(root->right));

        maxSum=max(maxSum,root->val+left+right);
        return root->val+max(left,right);  // agar maine curr node ko path me liya toh maxSum kitna hoga
    }
    int maxPathSum(TreeNode* root) {
        helper(root);
        return maxSum;
    }
};