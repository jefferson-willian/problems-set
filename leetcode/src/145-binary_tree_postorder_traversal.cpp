// PROBLEM: [Binary Tree Postorder Traversal](https://leetcode.com/problems/binary-tree-postorder-traversal)

class Solution {
 public:
  // Time Complexity  = O(n)
  // Space Complexity = O(h)
  //
  // n : tree nodes.
  // h : tree height.
  vector<int> postorderTraversal(TreeNode* root) {
    vector<int> solution;

    // Stack to postorder traversal.
    stack<pair<TreeNode*, bool>> s;

    // Add root node to the stack.
    if (root)
      s.emplace(root, false);

    // Each node is added to the queue two times, the second time the node is
    // considered visited.
    while (s.empty() == false) {
      // Get current node.
      TreeNode* node = s.top().first;
      bool visited = s.top().second;
      s.pop();

      // Check if node should be visited.
      if (visited) {
        solution.emplace_back(node->val);
        continue;
      }

      // Push node to be visited next time.
      s.emplace(node, true);

      // Add the right and left node
      if (node->right) s.emplace(node->right, false);
      if (node->left) s.emplace(node->left, false);
    }

    return solution;
  }
};
