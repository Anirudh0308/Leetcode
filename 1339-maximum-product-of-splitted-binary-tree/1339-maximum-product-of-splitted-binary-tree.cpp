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

    long M = 1e9+7;
    long totalSum = 0, maxP = 0;

    int findTotalSum(TreeNode* root) {
        if(!root)
            return 0;
        
        int leftSubtreeSum  = findTotalSum(root->left);
        int rightSubtreeSum = findTotalSum(root->right);
        int sum = root->val + leftSubtreeSum + rightSubtreeSum;
        
        maxP = max(maxP, (totalSum - sum) * sum);
        
        return sum;
    }

    int maxProduct(TreeNode* root) {
        if(!root)
            return 0;
        
        maxP = 0;
        
        totalSum = findTotalSum(root);
        findTotalSum(root);
        
        return maxP%M;
    }
};