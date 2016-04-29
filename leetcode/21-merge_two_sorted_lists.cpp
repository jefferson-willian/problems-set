class Solution {
 public:
  // Time Complexity  = O(n + m)
  // Space Complexity = O(1) 
  //
  // n : first list size.
  // m : second list size.
  ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    // Head of the merged list.
    ListNode* head_merged = nullptr;
    // Tail of the merged list.
    ListNode* tail_merged = nullptr;

    // Process all nodes in both lists.
    while (l1 || l2) {
      // Check which node will be inserted in the merged list. If the second
      // list is empty then insert a node from the first list. In the same way,
      // if the first list is empty then insert a node from the second list.
      // But, if both lists are not empty then insert the node from the list
      // that has lower value.
      ListNode* insert;
      if (l2 == nullptr || (l1 && l1->val <= l2->val)) {
        insert = l1;
        l1 = l1->next;
      } else { 
        insert = l2;
        l2 = l2->next;
      }

      // If the merged list is empty then updates the head of the merged list.
      if (head_merged == nullptr)
        head_merged = insert;

      // If the merged list is not empty then links the tail to the new node.
      if (tail_merged)
        tail_merged->next = insert;

      // Updates the tail of the merged list.
      tail_merged = insert;
    }

    return head_merged;
  }
};
