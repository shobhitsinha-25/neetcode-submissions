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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==0 && q==0) return true;
        if(p==0 && q!=0) return false;
        if(q==0 && p!=0) return false;

        if(p->val != q->val) return false;
        //else return true;

        bool left=isSameTree(p->left,q->left);
        bool right=isSameTree(p->right,q->right);

        if(left==false || right==false) return false;


        return true;
        
    }
};
