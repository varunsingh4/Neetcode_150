class Solution {
public:
    vector<vector<int>> ans;

    int dfs(TreeNode* root) {
        if (!root) return -1;

        int left = dfs(root->left);
        int right = dfs(root->right);

        int height = 1 + max(left, right);

        if (ans.size() == height) {
            ans.push_back({});
        }

        ans[height].push_back(root->val);

        return height;
    }

    vector<vector<int>> findLeaves(TreeNode* root) {
        dfs(root);
        return ans;
    }
};
