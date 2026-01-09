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
    bool allEqual(vector<TreeNode*>& v){
        for(int i=1;i<v.size();i++){
            if(v[i]!=v[i-1]){
                return false;
            }
        }
        return true;
    }
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        queue<pair<TreeNode*,int>> qu;

        unordered_map<TreeNode*,TreeNode*> parent_map;
        unordered_map<int,vector<TreeNode*>> level_map;

        qu.push({root,0});
        parent_map[root]=root;
        int maxLevel=0;

       

        while(!qu.empty()){
            auto it=qu.front();

            qu.pop();

            int currLevel=it.second;

            TreeNode* currNode=it.first;

            level_map[currLevel].push_back(currNode);

            maxLevel=max(maxLevel,currLevel);
           

            if(currNode->left){
                 parent_map[currNode->left]=currNode;
                qu.push({currNode->left,currLevel+1});
            }

            if(currNode->right){
                parent_map[currNode->right]=currNode;
                qu.push({currNode->right,currLevel+1});
            }


        }

        vector<TreeNode*> temp;

        temp=level_map[maxLevel];
        if(temp.size()==1) return temp[0];

        while(true){
            


            for(int i=0;i<temp.size();i++){
                temp[i]=parent_map[temp[i]];
            }

            if(allEqual(temp)){
                return temp[0];
            }
            else{
                continue;
            }
        }

        return root;
    }
};