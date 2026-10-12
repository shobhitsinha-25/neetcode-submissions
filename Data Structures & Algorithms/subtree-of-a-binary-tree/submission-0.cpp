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
    bool issame(TreeNode *p,TreeNode *q){
        if(p==0 && q==0) return true;
        if(p==0 && q!=0) return false;

        if(p!=0 && q==0) return false;
        if(p->val != q->val) return false;

        bool l=issame(p->left,q->left);
        bool r=issame(p->right,q->right);

        if(l==false || r==false) return false;

        return true;
    }
public:
    bool isSubtree(TreeNode* root, TreeNode* subroot) {
        if(root==0) return false;
        if(root->val==subroot->val){
            if(issame(root,subroot)) return true;
        }
        bool l=isSubtree(root->left,subroot);
        bool r=isSubtree(root->right,subroot);

        if(l==false && r==false) return false;

        return true;
    }
};
