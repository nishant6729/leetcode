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
    int leftCount(TreeNode* root){
        if(!root) return 0;
        return 1+ leftCount(root->left) + leftCount(root->right);
    }   
    int kthSmallest(TreeNode* root, int k) {
        if(!root) return -1; 
        int leftC=leftCount(root->left);

        if(k==leftC+1) return root->val;
        else if(k<=leftC) return kthSmallest(root->left,k);
        else{
            return kthSmallest(root->right,k-(leftC+1));
        }
    }
};