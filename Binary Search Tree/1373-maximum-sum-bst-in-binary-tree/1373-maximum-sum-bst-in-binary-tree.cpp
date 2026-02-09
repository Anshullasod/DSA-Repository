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
static int maxsum = 0;
class Solution {
public:
    class Info {
    public:
        bool isBST;
        int max, min, sum;
        Info(bool isBST, int max, int min, int sum) {
            this->isBST = isBST;
            this->max = max;
            this->min = min;
            this->sum = sum;
        }
    };
        Info* maxBST(TreeNode* root) {
        if (root == NULL) {
            return new Info(true, INT_MIN, INT_MAX, 0);
        }
        Info* leftinfo = maxBST(root->left);
        Info* rightinfo = maxBST(root->right);
        int currmax = max({root->val, leftinfo->max, rightinfo->max});
        int currmin = min({root->val, leftinfo->min, rightinfo->min});
        int currsum = leftinfo->sum + rightinfo->sum + root->val;
        if (leftinfo->isBST && rightinfo->isBST && leftinfo->max < root->val &&
            rightinfo->min > root->val) {
            maxsum = max(maxsum, currsum);
            return new Info(true, currmax, currmin, currsum);
        }
        return new Info(false, currmax, currmin, currsum);
    }
    int maxSumBST(TreeNode* root) {
        maxsum=0;
        maxBST(root);
        return maxsum;
    }
};