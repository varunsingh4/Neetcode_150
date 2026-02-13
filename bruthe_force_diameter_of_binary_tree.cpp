class Solution {
public:
    // Function to calculate the diameter of a binary tree
    int diameterOfBinaryTree(TreeNode* root) {
        // Base case: If the tree is empty, diameter = 0
        if(root == NULL) {
            return 0;
        }

        // Step 1: Compute the maximum height of left subtree
        // maxHeight(root->left) returns the longest path from root->left to a leaf
        int leftsubtreeMaxHeight = maxHeight(root->left);

        // Step 2: Compute the maximum height of right subtree
        int rightsubtreeMaxHeight = maxHeight(root->right);

        // Step 3: Compute diameter passing through the current root
        // Longest path through this node = left height + right height
        int diameter = leftsubtreeMaxHeight + rightsubtreeMaxHeight;

        // Step 4: Recursively compute the diameter of left and right subtrees
        // This handles the case where the longest path does NOT pass through the current root
        int sub = max(diameterOfBinaryTree(root->left),
                      diameterOfBinaryTree(root->right));

        // Step 5: Return the maximum of:
        // - diameter through current node
        // - diameter entirely in left or right subtree
        return max(sub, diameter);
    }

    // Helper function to calculate the maximum height of a subtree
    int maxHeight(TreeNode* root) {
        // Base case: Empty tree has height 0
        if(root == NULL) {
            return 0;
        }

        // Recursively calculate height of left subtree
        int left = maxHeight(root->left);

        // Recursively calculate height of right subtree
        int right = maxHeight(root->right);

        // Height of current node = 1 + max(left subtree height, right subtree height)
        // '+1' accounts for the current node itself
        return 1 + max(left, right);
    }
};
