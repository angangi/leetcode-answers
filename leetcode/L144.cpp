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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        pre(root, res);
        return res;
    }
    void pre(TreeNode* root, vector<int>& res) {
        if(root == nullptr) {
           return;
        }

        res.push_back(root->val);

        if(root->left != nullptr) {
            pre(root->left, res);
        }
        if(root->right != nullptr) {
            pre(root->right, res);
        }
    }
};
