/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    void pathsum(TreeNode* root, int target, vector<int>& temp,
                 vector<vector<int>>& result) {

        if (root == NULL) {
            return;
        }
        temp.push_back(root->val);
        if (target - root->val == 0 && root->left == NULL &&
            root->right == NULL) {
            result.push_back(temp);
        }
        pathsum(root->left, target - root->val, temp,result);
        pathsum(root->right, target - root->val, temp,result);
        temp.pop_back();

        return;
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> result;
        vector<int> temp;
        pathsum(root, targetSum, temp, result);
        return result;
    }
};