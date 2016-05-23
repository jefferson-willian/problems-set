class Solution {
 public:
  // Time Complexity  = O(n + m)
  // Space Complexity = O(n + m)
  //
  // n : first list size.
  // m : second list size.
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    // Answer list.
    ListNode* l3 = nullptr;

    // List iterators.
    ListNode* it1 = l1;
    ListNode* it2 = l2;
    ListNode* it3 = l3;

    // Holds the carry sum.
    int carry = 0;

    // We have three situations where we have to continue add numbers:
    //      - When the first iterator hasn't reached the end of the list.
    //      - When the second iterator hasn't reached the end of the  list.
    //      - When we have a carry value different than zero.
    while (it1 || it2 || carry > 0) {
      // Get the first and second numbers to sum if the iterators haven't
      // reached the end of the lists, otherwise uses 0 to sum.
      int a = it1 ? it1->val : 0;
      int b = it2 ? it2->val : 0;

      // Sum both numbers and the carry as well.
      int val = a + b + carry;

      // Appends the sum to the answer list.
      if (l3 == nullptr)
        l3 = new ListNode(val % 10);
      else
        it3->next = new ListNode(val % 10);

      // Update iterators if they haven't reached the end of the lists.
      it1 = it1 ? it1->next : nullptr;
      it2 = it2 ? it2->next : nullptr;
      it3 = it3 ? it3->next : l3;

      // Updates the carry sum.
      carry = val / 10;
    }

    // Returns the answer.
    return l3;
  }
};
