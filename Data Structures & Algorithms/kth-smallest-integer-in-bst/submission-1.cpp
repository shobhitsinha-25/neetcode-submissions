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
    void inorder(TreeNode *root,int &k,int &count,int &ans)
    {
        if(root==0) return;
        inorder(root->left,k,count,ans);
        count++;
        if(count==k) ans=root->val;
        inorder(root->right,k,count,ans);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        //vector<int> v;
        int ans=-1;
        int count=0;
        inorder(root,k,count,ans);

        int index=k-1;
        //return v[index];
        return ans;
    }
};
