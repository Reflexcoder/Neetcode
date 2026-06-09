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

    int solve(TreeNode* root, unordered_map<TreeNode*,int>&mapp){
        if(root==NULL){
            return 0;
        }
        if(mapp.find(root)!=mapp.end()){
            return mapp[root];
        }
        int take_root=root->val;
        if(root->left!=NULL){
            take_root+=solve(root->left->left,mapp) + solve(root->left->right,mapp);
        }
        if(root->right!=NULL){
            take_root+=solve(root->right->left,mapp) + solve(root->right->right,mapp);
        }
        int skip_root=solve(root->left,mapp) + solve(root->right,mapp);
        return mapp[root]=max(take_root,skip_root);
    }
    
    int rob(TreeNode* root) {
       if(root==NULL){
        return 0;
       }
        unordered_map<TreeNode*,int>mapp;
        int ans=solve(root,mapp);
        return ans;
       
    }
};