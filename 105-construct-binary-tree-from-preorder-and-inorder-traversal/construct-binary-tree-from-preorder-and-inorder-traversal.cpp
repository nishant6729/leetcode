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
    TreeNode* makeTree(int sidx,int eidx,int &idx,vector<int>& preorder, vector<int>& inorder){
        if(sidx>eidx) return NULL;
       
        int target=preorder[idx++];
        TreeNode* root=new TreeNode(target);
        int tempIdx;
        for(int i=sidx;i<=eidx;i++){
            if(inorder[i]==target){
                tempIdx=i;
                break;
            }
        }
        root->left=makeTree(sidx,tempIdx-1,idx,preorder,inorder);
        root->right=makeTree(tempIdx+1,eidx,idx,preorder,inorder);
        return root;

    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int idx=0;
        return makeTree(0,inorder.size()-1,idx,preorder,inorder);
    }
};