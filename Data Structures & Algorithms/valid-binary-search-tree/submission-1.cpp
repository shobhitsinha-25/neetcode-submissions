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

    bool sol(TreeNode *root,int mini,int maxi)
    {
        if(root==0) return true;
        if(root->val<=mini || root->val>=maxi) return false;

        return sol(root->left,min(root->val,mini),root->val) && sol(root->right,max(root->val,mini),maxi);
    }
public:
    bool isValidBST(TreeNode* root) {
        return sol(root,INT_MIN,INT_MAX);
    }
};
