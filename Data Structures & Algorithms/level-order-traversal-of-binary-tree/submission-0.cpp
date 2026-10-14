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
   /* void sol(TreeNode *r,queue<int> &q,vector<vector<int>> &ans)
    {
        if(r==0) return;
        int qsize=q.size();
        vector<int> temp;
        while(!q.empty())
        {
            TreeNode *node=q.front();
            temp.push_back(node->val);
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);

            q.pop();
        }
        

        ans.push_back(temp);
        sol(r->left,q,ans);
        sol(r->right,q,ans);
    }*/
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode *> q;
        q.push(root);

        vector<vector<int>> ans;
        if(root==0) return ans;
        //int qsize=q.size();
        vector<int> temp;
        while(!q.empty())
        {
            int qsize=q.size();
            vector<int> temp;
            while(qsize>0){
            TreeNode *node=q.front();
            q.pop();
            temp.push_back(node->val);
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
            qsize--;
            }
            
            ans.push_back(temp);
            
        }

        return ans;
    }
};
