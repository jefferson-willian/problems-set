class Solution {
 public:
  // Time Complexity  = O(n + m)
  // Space Complexity = O(n + m) 
  //
  // n : string |a| size.
  // m : string |b| size.
  string addBinary(const string& a, const string& b) {
    int n = a.length();
    int m = b.length();

    string ret;
    int carry = 0;

    // Process all bits from right to left.
    for (int i = 0; i < max(n, m); ++i) {
      // Get bits if they are in the range of the string, otherwise get 0 by
      // default.
      int bit1 = i < n ? a[n - 1 - i] - '0' : 0;
      int bit2 = i < m ? b[m - 1 - i] - '0' : 0;

      // Add bits and save it to the answer.
      ret.push_back('0' + (bit1 + bit2 + carry & 1));

      // Updates carry.
      carry = bit1 + bit2 + carry >> 1;
    }

    // If there is a carry left then appends to the answer.
    if (carry)
      ret.push_back('1');

    // Reverse the string to show the bits in the correct order.
    reverse(ret.begin(), ret.end());

    return ret;
  }
};
