// PROBLEM: [Balanced Binary Tree](https://leetcode.com/problems/balanced-binary-tree)

struct MySolution {
  int depth = 0;
  bool balanced = true;
};

class Solution {
 public:
  // Time Complexity  = O(n)
  // Space Complexity = O(1)
  //
  // n : tree nodes.
  MySolution solve(TreeNode* root) {
    MySolution solution;

    // Check if there is no tree.
    if (root == nullptr) 
      return solution;

    // Check solutions from both subtrees.
    const MySolution& solution_left = solve(root->left);
    const MySolution& solution_right = solve(root->right);

    // Check if subtree is balanced.
    if (abs(solution_left.depth - solution_right.depth) > 1
        || !solution_left.balanced || !solution_right.balanced)
      solution.balanced = false;

    // If it is not balanced just return.
    if (!solution.balanced)
      return solution;

    // Update depth an return.
    solution.depth = max(solution_left.depth, solution_right.depth) + 1;
    solution.balanced = true;

    return solution;
  }

  bool isBalanced(TreeNode* root) {
    return solve(root).balanced;
  }
};
