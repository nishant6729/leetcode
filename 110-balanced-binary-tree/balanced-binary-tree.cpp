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
    int height(TreeNode* root){
        if(!root) return 0;

        int leftPart=height(root->left);

        if(leftPart==-1) return -1;

        int rightPart=height(root->right);

        if(rightPart==-1) return -1;

        if(abs(leftPart-rightPart)>1) return -1;

        return 1+max(leftPart,rightPart);
    }
    bool isBalanced(TreeNode* root) {
        return height(root)!=-1;
    }
};