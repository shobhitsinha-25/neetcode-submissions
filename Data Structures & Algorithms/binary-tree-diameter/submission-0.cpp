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
    int sol(TreeNode *root,int &d)
    {
        if(root==0) return 0;

        int lheight=sol(root->left,d);
        int rheight=sol(root->right,d);

        d=max(d,lheight+rheight);

        return 1+max(lheight,rheight);
    }
    
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int d=0;
        sol(root,d);
        return d;
    }
};
