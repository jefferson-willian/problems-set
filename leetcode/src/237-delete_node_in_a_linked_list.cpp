class Solution {
 public:
  // Time Complexity  = O(1)
  // Space Complexity = O(1) 
  void deleteNode(ListNode* node) {
    // Clone the next node value to the current node (the node supposed to be
    // deleted), and instead to delete the current node we delete the next node.
    node->val = node->next->val;
    // Hold the next node to delete.
    ListNode* to_delete = node->next;
    // Update link of the current node.
    node->next = node->next->next;
    // Delete the node.
    delete to_delete;
  }
};
