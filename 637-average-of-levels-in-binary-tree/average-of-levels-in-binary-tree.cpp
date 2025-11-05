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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> ans;
        queue<TreeNode*> qu;

        qu.push(root);

        while(!qu.empty()){
            int k=qu.size();
            int s=k;
            double sum=0;
            while(k--){
                auto node=qu.front();

                qu.pop();

                if(node->left) qu.push(node->left);
                if(node->right) qu.push(node->right);

                sum+=node->val;
            }
            double avg=sum/s;
            ans.push_back(avg);
        }
        return ans;
    }
};