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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> nums;
        if (root == NULL) {
            return nums;
        }
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int idx=q.size();
            vector<int> curr;
            for (int i = 0; i < idx; i++) {
                TreeNode* temp = q.front();
                q.pop();
                curr.push_back(temp->val);
                if (temp->left != NULL) {
                    q.push(temp->left);
                }
                if (temp->right != NULL) {
                    q.push(temp->right);
                }}
                nums.push_back(curr);
            
        }
        return nums;
    }
};