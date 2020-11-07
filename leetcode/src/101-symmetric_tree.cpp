class Solution {
 public:
  // Time Complexity  = O(n)
  // Space Complexity = O(1)
  //
  // n : tree nodes.
  bool solve(TreeNode* p, TreeNode* q) {
    // Check if there is no trees.
    if (p == nullptr && q == nullptr) return true;

    // Check if one tree finished before the other.
    if (p == nullptr || q == nullptr || p->val != q->val) return false;

    return solve(p->left, q->right) && solve(p->right, q->left);
  }

  bool isSymmetric(TreeNode* root) {
    return root == nullptr || solve(root->left, root->right);
  }
};
