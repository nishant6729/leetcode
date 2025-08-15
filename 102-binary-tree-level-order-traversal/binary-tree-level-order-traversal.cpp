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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> qu;
        qu.push(root);
        vector<vector<int>> ans;
        if(root==NULL) return ans;
        while(!qu.empty()){
            int k=qu.size();
            vector<int> v;
            while(k--){
                
                TreeNode* temp=qu.front();
                qu.pop();
                if(temp){
                    v.push_back(temp->val);
                }
                if(temp->left) qu.push(temp->left);
                if(temp->right) qu.push(temp->right);
            }
            ans.push_back(v);
        }
        return ans;
    }
};