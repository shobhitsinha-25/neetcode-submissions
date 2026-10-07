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

    int sol(TreeNode *root)
    {
        if(root==0) return 0;

        int l=sol(root->left);
        int r=sol(root->right);

        if(l==-1 || r==-1) return -1;

        if(abs(l-r)>1) return -1;

        return 1+max(l,r);
    }
public:
    bool isBalanced(TreeNode* root) {
        int ans=sol(root);
        if(ans==-1) return false;

        return true;
    }
};
