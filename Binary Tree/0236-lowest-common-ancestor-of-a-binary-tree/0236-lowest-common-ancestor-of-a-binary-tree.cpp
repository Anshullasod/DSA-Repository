/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
TreeNode* LCA(TreeNode* root,TreeNode* n1,TreeNode* n2)
{
  if(root==NULL)
  {
    return NULL;
  }
  if(root==n1||root==n2)
  {
    return root;
  }
  TreeNode* lr=LCA(root->left,n1,n2);
  TreeNode* rr=LCA(root->right,n1,n2);
  if(lr!=NULL&&rr!=NULL)
  {
    return root;
  }
  if(lr!=NULL)
  {
    return lr;
  }
  if(rr!=NULL)
  {
    return rr;
  }
  return NULL;
}
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* ans=LCA(root,p,q);
        return ans;
    }
};