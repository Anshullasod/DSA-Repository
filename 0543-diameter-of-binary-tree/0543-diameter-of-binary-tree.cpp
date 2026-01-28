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
    int height(TreeNode* root)
    {
        if(root==NULL)
        {
            return 0;
        }
        int lh=height(root->left);
        int rh=height(root->right);
        int ch=max(lh,rh);
        return ch+1;
    }
    pair<int,int> diameter(TreeNode* root)
    {
        if(root==NULL)
        {
            return make_pair(0,0); //Diameter,height
        }
        pair<int,int> lef=diameter(root->left);
        pair<int,int> rig=diameter(root->right);
        int cd=lef.second+rig.second;
        int md=max({lef.first,rig.first,cd});
        int fh=max(lef.second,rig.second);
        return make_pair(md,height(root));
    }
    int diameterOfBinaryTree(TreeNode* root) {
        return diameter(root).first;
    }
};