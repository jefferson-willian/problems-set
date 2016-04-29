class Solution {
 public:
  // Time Complexity  = O(n * log n)
  // Space Complexity = O(1) 
  //
  // n : list size.
  ListNode* sortList(ListNode* head) {
    // Sort only if there is at least two nodes.
    if (head == nullptr || head->next == nullptr)
      return head;

    // Get the pointer to the half of the list.
    ListNode* half = getHalf(head);

    // First half of the list.
    ListNode* l1 = head;
    // Second half of the list.
    ListNode* l2 = half->next;
    half->next = nullptr;

    // Merge the two sorted lists.
    //
    // Ps.: See the problem "21 - Merge two sorted lists".
    return mergeTwoLists(sortList(l1), sortList(l2));
  }

  // Return the node that is in the middle of the list.
  ListNode* getHalf(ListNode* head) {
    ListNode* tail = head;
    ListNode* half = nullptr;
    while (tail) {
      half = half ? half->next : head;
      tail = tail->next ? tail->next->next : nullptr;
    }

    return half;
  }
};
