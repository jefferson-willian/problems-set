class Solution {
 public:
  // Time Complexity  = O(n + m)
  // Space Complexity = O(n + m) 
  //
  // n : first list size.
  // m : second list size.
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    // First number iterator.
    ListNode* it1 = l1;
    // Second number iterator.
    ListNode* it2 = l2;
    // Answer iterator.
    ListNode* it3 = nullptr;

    // !Important! I am considering that the list input will have at least one
    // node. This is the case where 0 is represented by a list with one node
    // with value 0. If we allow empty lists as input then this will fail.
    //
    // Sum the first number of both lists and saves the result in the list
    // |head| (The head of the list answer).
    int val = it1->val + it2->val;
    ListNode* head = new ListNode(val % 10);

    // Keeps the sum carry.
    int carry = val / 10;

    // Update the iterators.
    it1 = it1->next;
    it2 = it2->next;
    it3 = head;

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
      it3->next = new ListNode(val % 10);
      // Update iterators if they haven't reached the end of the lists.
      if (it1) it1 = it1->next;
      if (it2) it2 = it2->next;
      it3 = it3->next;
      // Updates the carry.
      carry = val / 10;
    }

    // Returns the answer.
    return head;
  }
};
