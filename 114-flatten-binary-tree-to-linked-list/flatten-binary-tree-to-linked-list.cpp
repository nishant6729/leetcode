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
    queue<TreeNode*> qu;
    void performOperation(TreeNode* root){
        if(!root) return;
        qu.push(root);
        performOperation(root->left);
        performOperation(root->right);
    }
    void flatten(TreeNode* root) {
        
        performOperation(root);
        while(!qu.empty()){
            TreeNode* temp=qu.front();
            qu.pop();
            temp->left=NULL;
            if(!qu.empty()) temp->right=qu.front();
            else temp->right=NULL;
        }   
        
    }
};