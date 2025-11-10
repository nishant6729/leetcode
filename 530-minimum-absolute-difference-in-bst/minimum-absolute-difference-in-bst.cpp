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
    void traverse(vector<int> &v,TreeNode* root){
        if(!root) return;
        v.push_back(root->val);
        traverse(v,root->left);
        traverse(v,root->right);
    }
    int getMinimumDifference(TreeNode* root) {
        vector<int> v;
        traverse(v,root);
        sort(v.begin(),v.end());
        int ans=INT_MAX;
        int n=v.size();
        for(int i=0;i<n-1;i++){
            ans=min(ans,v[i+1]-v[i]);
        }   
        return ans;
    }
};