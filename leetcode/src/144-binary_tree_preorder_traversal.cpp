// PROBLEM: [Binary Tree Preorder Traversal](https://leetcode.com/problems/binary-tree-preorder-traversal)

class Solution {
 public:
  // Time Complexity  = O(n)
  // Space Complexity = O(h)
  //
  // n : tree nodes.
  // h : tree height.
  vector<int> preorderTraversal(TreeNode* root) {
    vector<int> solution;

    // Preorder stack.
    stack<TreeNode*> s;

    // Add root to the stack.
    if (root)
      s.push(root);

    // Process every node.
    while (s.empty() == false) {
      // Get next node of the preorder traversal.
      TreeNode* node = s.top();
      s.pop();

      // Add node to the solution.
      solution.emplace_back(node->val);

      // Add right and left node to the stack.
      if (node->right) s.push(node->right);
      if (node->left) s.push(node->left);
    }

    return solution;
  }
};
