// PROBLEM: [Diameter of Binary Tree](https://leetcode.com/problems/diameter-of-binary-tree)

class Solution {
 public:
  // Time Complexity  = O(n)
  // Space Complexity = O(1)
  //
  // n : tree nodes.
  //
  // Returns a pair containing the maximum distance from root to any leaf and
  // the maximum diameter in root subtree.
  pair<int, int> solve(TreeNode* root) {
    // Returns zero if there is no tree.
    if (root == nullptr)
      return pair<int, int>(0, 0);

    // Get the solutions from subtrees.
    const pair<int, int>& sol_left = solve(root->left);
    const pair<int, int>& sol_right = solve(root->right);

    // Get maximum distances from this root to any leaf in left subtree and any
    // leaf in right subtree.
    int dist_left = root->left ? 1 + sol_left.first : 0;
    int dist_right = root->right ? 1 + sol_right.first : 0;

    // Get best diameter so far from subtrees.
    int best_diameter = max(sol_left.second, sol_right.second);

    // Returns maximum distance from this root to any leaf and maximum diameter
    // from current subtree.
    return pair<int, int>(max(dist_left, dist_right),
        max(best_diameter, dist_left + dist_right));
  }

  int diameterOfBinaryTree(TreeNode* root) {
    return solve(root).second;
  }
};
