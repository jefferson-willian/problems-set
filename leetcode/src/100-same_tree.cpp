class Solution {
 public:
  // Time Complexity  = O(n)
  // Space Complexity = O(1)
  //
  // n : tree nodes.
  bool isSameTree(TreeNode* p, TreeNode* q) {
    // Check if there is no tree.
    if (p == nullptr && q == nullptr)
      return true;

    // Check if only one subtree is a leaf or if values are different
    if (p == nullptr || q == nullptr || p->val != q->val)
      return false;

    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
  }
};
