class Solution {
public:
    // Helper function to build the tree using preorder and inorder traversal
    TreeNode* build(vector<int>& preorder, int preStart,
                    vector<int>& inorder, int inStart, int inEnd) {

        // Base case:
        // If preorder index goes out of bounds OR
        // inorder range becomes invalid, there is no subtree to build
        if (preStart >= preorder.size() || inStart > inEnd) {
            return NULL;
        }

        // The first element in preorder is always the root of the current subtree
        TreeNode* root = new TreeNode(preorder[preStart]);

        // Find the index of the root in inorder traversal
        // Elements to the left of this index belong to the left subtree
        // Elements to the right belong to the right subtree
        int index = inStart;
        while (inorder[index] != root->val) {
            index++;
        }

        // Number of nodes in the left subtree
        int leftSize = index - inStart;

        // Recursively build the left subtree
        // Next preorder element is the root of the left subtree
        // Inorder range: inStart to index - 1
        root->left = build(preorder, preStart + 1,
                           inorder, inStart, index - 1);

        // Recursively build the right subtree
        // Skip left subtree nodes in preorder
        // Inorder range: index + 1 to inEnd
        root->right = build(preorder, preStart + leftSize + 1,
                            inorder, index + 1, inEnd);

        // Return the constructed subtree rooted at 'root'
        return root;
    }

    // Main function to construct the binary tree
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

        // Start building the tree from the full preorder and inorder arrays
        return build(preorder, 0, inorder, 0, inorder.size() - 1);
    }
};
