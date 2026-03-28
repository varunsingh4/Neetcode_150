class Solution {
public:
    void flatten(TreeNode* root) {
        
        TreeNode* cur = root;

        // We walk through the tree using a pointer (no recursion, no stack)
        while (cur != NULL) {

            // If current node has a left subtree,
            // we need to "insert" it between current node and right subtree
            if (cur->left != NULL) {

                // STEP 1: Find the rightmost node of the left subtree
                // This node will become the "bridge" to connect to the right subtree
                TreeNode* prev = cur->left;
                while (prev->right != NULL) {
                    prev = prev->right;
                }

                // STEP 2: Connect the rightmost node of left subtree
                // to the original right subtree
                // (so we don't lose the right part of the tree)
                prev->right = cur->right;

                // STEP 3: Move the entire left subtree to the right side
                // because final structure is only right pointers
                cur->right = cur->left;

                // STEP 4: Set left to NULL because we are flattening into a linked list
                cur->left = NULL;
            }

            // STEP 5: Move to next node in the "linked list"
            cur = cur->right;
        }
    }
};
