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
    int balancedheight(TreeNode* root)
    {
        if(root==NULL)
        {
            return 0;
        }
        
        int lh=balancedheight(root->left);
        if(lh==-1)
        {
            return -1;
        }
        int rh=balancedheight(root->right);
        if(rh==-1)
        {
            return -1;
        }
        int ch=max(lh,rh);
        if(abs(lh-rh)>1)
        {return -1;}
        return ch+1;
    }
    bool isBalanced(TreeNode* root) {
        if(balancedheight(root)==-1)
        {
          return false;
        }
        return true;
    }
};