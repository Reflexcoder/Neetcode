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
    int solve(TreeNode* root, int value){
          if(root==NULL){
            return 0;
          }
          int count=0;
          if(root->val>=value){
            count++;
          }
          value=max(value,root->val);
          count+=solve(root->left,value);
         count+= solve(root->right,value);

          return count;

    }
    int goodNodes(TreeNode* root) {
       
      int ans=solve(root, INT_MIN);
      return ans;
    }
};
