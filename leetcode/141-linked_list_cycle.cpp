class Solution {
public:
  // Time Complexity  = O(n)
  // Space Complexity = O(1) 
  //
  // n : list size.
  bool hasCycle(ListNode *head) {
    // Check if the list has at least two nodes.
    if (head == nullptr || head->next == nullptr)
      return false;

    // Points the slow iterator to the first node, and the fast iterator to the
    // second node.
    ListNode* slow_iterator = head;
    ListNode* fast_iterator = head->next;

    // Iterate through the list by making the slow iterator moving at one node
    // at time and the fast iterator at two nodes at time.
    while (slow_iterator && fast_iterator) {
      // If there is a cycle then they must reach at some point.
      if (slow_iterator == fast_iterator)
        return true;

      // Update iterators.
      slow_iterator = slow_iterator->next;
      fast_iterator = (fast_iterator->next ? fast_iterator->next->next :
          nullptr);
    }

    // If one of the iterators reaches the end of the list then we can conclude
    // that there is no cycle in the list.
    return false;
  }
};
