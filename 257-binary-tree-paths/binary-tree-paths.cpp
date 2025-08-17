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
    vector<string> ans;
    void dfs(TreeNode* root,string s){
        if(root==NULL) return;
        if(root->left==NULL && root->right==NULL){
            s+=to_string(root->val);
            ans.push_back(s);
        }
        string temp=s+to_string(root->val)+"->";
        dfs(root->left,temp);
        dfs(root->right,temp);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        dfs(root,"");
        return ans;
    }
};