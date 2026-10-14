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

    void sol(TreeNode *root,int currmaxi,int &count)
    {
        if(root==0) return;

        if(root->val>=currmaxi) count++;
        currmaxi=max(currmaxi,root->val);
        

        sol(root->left,currmaxi,count);
        sol(root->right,currmaxi,count);
    }
public:
    int goodNodes(TreeNode* root) {
        int currmaxi=INT_MIN;
        int count=0;

        sol(root,currmaxi,count);

        return count;
    }
};
