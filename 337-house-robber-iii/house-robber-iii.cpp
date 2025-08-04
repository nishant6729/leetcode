class Solution {
public:
    unordered_map<TreeNode*,array<int,2>> mp;
    int helper(TreeNode* root,int flag){
        if(root==NULL) return 0;
        if (mp.find(root) == mp.end()) mp[root] = {-1, -1};

        // If already computed
        if (mp[root][flag] != -1) return mp[root][flag];
       
        if(flag==1){
            int take=root->val+helper(root->left,0)+helper(root->right,0);
            int not_take=helper(root->left,1)+helper(root->right,1);
            return mp[root][flag]=max(take,not_take);
        }   
        else{
            return mp[root][flag]=helper(root->left,1)+helper(root->right,1);
        }
    }
    int rob(TreeNode* root) {
        int ans=helper(root,1);
        return ans;
    }
};