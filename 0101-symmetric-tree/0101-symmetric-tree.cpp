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
    bool ischeck(TreeNode* lef,TreeNode* rig)
    {    if(lef==NULL&&rig==NULL)
        {
          return true;
        }
        if(lef==NULL||rig==NULL)
        {
          return false;
        }
        if(lef->val!=rig->val)
        {
           return false;
        }
        return ischeck(lef->left,rig->right)&&ischeck(lef->right,rig->left);
       
    }
    bool isSymmetric(TreeNode* root) {
        return ischeck(root->left,root->right);
    }
};