class NodeValue{
public:
    long long minVal, maxVal, sum;

    NodeValue(long long minval, long long maxval, long long sum){
        minVal = minval;
        maxVal = maxval;
        this->sum = sum;
    }
};

class Solution {
public:
    long long maxSum = 0;

    NodeValue helper(TreeNode* root){
        if(!root){
            return NodeValue(LLONG_MAX, LLONG_MIN, 0);
        }

        auto left = helper(root->left);
        auto right = helper(root->right);

        // If valid BST
        if(left.maxVal < root->val && right.minVal > root->val){

            long long currSum = left.sum + right.sum + root->val;

            maxSum = max(maxSum, currSum);

            return NodeValue(
                min((long long)root->val, left.minVal),
                max((long long)root->val, right.maxVal),
                currSum
            );
        }

        // Not a BST
        return NodeValue(LLONG_MIN, LLONG_MAX, 0);
    }

    int maxSumBST(TreeNode* root) {
        helper(root);
        return maxSum;
    }
};
