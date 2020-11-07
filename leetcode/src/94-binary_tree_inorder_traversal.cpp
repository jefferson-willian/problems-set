// PROBLEM: [Binary Tree Inorder Traversal](https://leetcode.com/problems/binary-tree-inorder-traversal)

class Solution {
 public:
  // Time Complexity  = O(n)
  // Space Complexity = O(h)
  //
  // n : tree nodes.
  vector<int> inorderTraversal(TreeNode* root) {
    vector<int> solution;

    // Stack to inorder traversal.
    stack<TreeNode*> s;

    // Add every node in the left call of the inorder traversal.
    while (root) {
      s.push(root);
      root = root->left;
    }

    // Process every node.
    while (s.empty() == false) {
      // Get current node.
      solution.emplace_back(s.top()->val);
      TreeNode* node = s.top();
      s.pop();

      // Add every node in left call of the inorder traversal for the right
      // node.
      node = node->right;
      while (node) {
        s.push(node);
        node = node->left;
      }
    }

    return solution;
  }
};
