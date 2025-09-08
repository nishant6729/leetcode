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
    vector<string> temp;
    void dfs(TreeNode* root,string s){
        if(root->left==NULL && root->right==NULL){
            temp.push_back(s+to_string(root->val));
        }
        string t=to_string(root->val);
        if(root->left) dfs(root->left,s+t);
        if(root->right) dfs(root->right,s+t);
    }
    int sumNumbers(TreeNode* root) {
        dfs(root,"");
        int ans=0;
        for(auto s:temp){
            ans+=stoi(s);
        }
        return ans;
    }
};