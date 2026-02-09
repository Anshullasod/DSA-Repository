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
    void helper(vector<int> &num,TreeNode* root)
    {
        if(root==NULL){
            return;
        }
        helper(num,root->left);
        num.push_back(root->val);
        helper(num,root->right);
    }
    int kthSmallest(TreeNode* root, int k) {
       vector<int> num;
       helper(num,root);
       return num[k-1];
    }
};