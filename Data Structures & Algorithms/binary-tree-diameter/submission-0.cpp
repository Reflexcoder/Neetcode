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
int diam(TreeNode* root,int &maxh){
    if(root==NULL){
        return 0;
    }
    maxh=0;
    int left=diam(root->left,maxh);
    int right=diam(root->right,maxh);
    maxh=max(maxh,left+right);
    return 1 + max(left,right);
    
}
    int diameterOfBinaryTree(TreeNode* root) {
        int maxh=0;
        diam(root,maxh);
        return maxh;
        
    }
};
