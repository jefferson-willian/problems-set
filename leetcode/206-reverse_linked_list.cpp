class Solution {
 public:
  // Time Complexity  = O(n)
  // Space Complexity = O(1) 
  //
  // n : list size.
  ListNode* reverseList(ListNode* head) {
    // Hold the previous and the current processed nodes.
    ListNode* prev = nullptr;
    ListNode* curr = head;

    // Process all nodes in the list.
    while (curr) {
      // Hold the next node to process.
      ListNode* next = curr->next;
      // Point the next link of the current node to the previous node.
      curr->next = prev;
      // Update previous and current nodes.
      prev = curr;
      curr = next;
    }

    // Return the last processed node.
    return prev;
  }
};
