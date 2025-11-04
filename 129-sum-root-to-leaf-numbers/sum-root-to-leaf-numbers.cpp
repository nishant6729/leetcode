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
    queue<string> qu;
    void dfs(TreeNode* root,string s){
        if(!root) return;
        if(!root->left && !root->right){
            qu.push(s+to_string(root->val));
            return ;
        } 
        string temp=s+to_string(root->val);
         dfs(root->left,temp);
         dfs(root->right,temp);
    }
    int sumNumbers(TreeNode* root) {
        dfs(root,"");
        int sum=0;
        while(!qu.empty()){
            if(qu.front()!=""){
                sum+=stoi(qu.front());
                qu.pop();
            }
            else qu.pop();
        }
        return sum;
    }
};