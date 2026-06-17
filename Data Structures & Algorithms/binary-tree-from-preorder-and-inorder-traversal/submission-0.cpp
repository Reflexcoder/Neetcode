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

    TreeNode* solve(vector<int>& preorder, vector<int>& inorder,int preStart, int inStart,int inEnd, map<int,int>&mp){
        if(preStart>=preorder.size() || inStart>inEnd){
            return NULL;
        }
        int rootVal=preorder[preStart];
        TreeNode* root=new TreeNode(rootVal);
        int mid=mp[rootVal];
        int leftsize=mid-inStart;
        root->left=solve(preorder,inorder,preStart+1,inStart,mid-1,mp);
        root->right=solve(preorder,inorder,preStart+leftsize+1,mid+1,inEnd,mp);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int,int>mp;
        for(int i=0;i<inorder.size();i++){
           mp[inorder[i]]=i;
        }
       return solve(preorder,inorder,0,0,inorder.size()-1,mp);
    }
};
