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
    int count=0;
    // dfs ka kaam count dena nhi hai uska kaam hai btana ki koi node 3 me se konsi state me hai 
    int dfs(TreeNode* root){
        if(!root) return 1; // covered state hai null ki
        int left=dfs(root->left);
        int right=dfs(root->right);
        if(left==0 || right==0){
            count++;
            return 2;
        }
        if(left==2 || right==2){
            return 1;
        }
        return 0;
    }
    int minCameraCover(TreeNode* root) {
        // 3 cases banenge 1. covered hai 2. covered ni hai 3. camera placed hai
        if(dfs(root)==0){
            // root covered nhi hai
            count++;
        }
        return count;
    }
};