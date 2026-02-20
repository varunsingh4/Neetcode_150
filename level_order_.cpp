class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (root == nullptr) return {};

        vector<vector<int>> v1;
        queue<TreeNode*> q1;
        q1.push(root);

        while (!q1.empty()) {

            vector<int> currentLevel;
            int size = q1.size();

            for (int i = 0; i < size; i++) {
                TreeNode* curr = q1.front();
                q1.pop();

                currentLevel.push_back(curr->val);

                if (curr->left != nullptr)
                    q1.push(curr->left);

                if (curr->right != nullptr)
                    q1.push(curr->right);
            }

            v1.push_back(currentLevel);
        }

        return v1;
    }
};
