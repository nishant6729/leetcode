class Solution {
public:
    void inorder(TreeNode* root,vector<int> &in){
        if(root==NULL) return;
        inorder(root->left,in);
        in.push_back(root->val);
        inorder(root->right,in);
    }
    TreeNode* construct(vector<int> in,int lo,int hi){
        if(lo>hi) return NULL;
        int mid=lo+(hi-lo)/2;
        TreeNode* root=new TreeNode(in[mid]);
        if(lo==hi) return root;
        root->left=construct(in,lo,mid-1);
        root->right=construct(in,mid+1,hi);
        return root;
    }
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> in;
        inorder(root,in);
        int n=in.size();
        
        TreeNode* newroot=construct(in,0,n-1);
        return newroot;
    }
};