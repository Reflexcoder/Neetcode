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

    int solve(TreeNode* root, int &current_sum){
        if(root==NULL){
            return 0;
        }
        int left=max(0,solve(root->left,current_sum));
        int right=max(0,solve(root->right,current_sum));
        current_sum=max(current_sum,root->val + left + right);
        return root->val + max(left,right);

    }
public:
    int maxPathSum(TreeNode* root) {
        
        int current_sum=INT_MIN;
        solve(root,current_sum);
        return current_sum;
    }
};
