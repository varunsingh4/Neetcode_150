class Solution {
public:
    // This variable stores the maximum diameter found so far
    int ans = 0;

    // DFS function returns the height of the current subtree
    int dfs(TreeNode* root) {
        // Base case: If the node is null, its height is 0
        if(!root) {
            return 0;
        }

        // Recursively compute the height of the left subtree
        // This is the longest path from root->left to any leaf
        int leftHeight = dfs(root->left);

        // Recursively compute the height of the right subtree
        int rightHeight = dfs(root->right);

        // Update the diameter:
        // The longest path **through this node** is leftHeight + rightHeight
        // We compare it with the previously stored maximum diameter
        ans = max(ans, leftHeight + rightHeight);

        // Return the height of this node to its parent:
        // Height = 1 (for the current node itself) + max height of its subtrees
        return 1 + max(leftHeight, rightHeight);
    }

    // Main function to calculate diameter of binary tree
    int diameterOfBinaryTree(TreeNode* root) {
        // Start DFS from root. 
        // The dfs function will update 'ans' for all nodes.
        dfs(root);

        // 'ans' now contains the maximum diameter of the tree
        return ans;
    }
};
