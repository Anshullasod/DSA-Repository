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
    int rangesum(int &sum,TreeNode* root,int low,int high)
    {
        if(root==NULL)
        {
            return sum;
        }
        if(root->val>=low&&root->val<=high)
        {
            sum+=root->val;
        }
        rangesum(sum,root->left,low,high);
        rangesum(sum,root->right,low,high);
        return sum;

    }
    int rangeSumBST(TreeNode* root, int low, int high) {
        int sum=0;
        sum=rangesum(sum,root,low,high);
        return sum;
    }
};