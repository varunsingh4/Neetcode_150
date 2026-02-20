class Solution {
public:
    bool isValid(TreeNode* root, long long MIN, long long MAX) {
        if (root == NULL) return true;
        if (root->val <= MIN || root->val >= MAX) return false;

        return isValid(root->left, MIN, root->val) &&
               isValid(root->right, root->val, MAX);
    }

    bool isValidBST(TreeNode* root) {
        return isValid(root, LLONG_MIN, LLONG_MAX);
    }
};
