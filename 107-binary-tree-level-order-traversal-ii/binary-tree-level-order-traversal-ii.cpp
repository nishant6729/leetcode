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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        queue<TreeNode*> qu;
        qu.push(root);
        
        vector<vector<int>> ans;
        if(!root) return ans;
        while(!qu.empty()){
            int k=qu.size();
            vector<int> temp;
            while(k--){
                temp.push_back(qu.front()->val);
                if(qu.front()->left) qu.push(qu.front()->left);
                if(qu.front()->right) qu.push(qu.front()->right);
                qu.pop();
            }
            ans.push_back(temp);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};