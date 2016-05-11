class Solution {
 public:
  // Time Complexity  = O(n ^ 2)
  // Space Complexity = O(n)
  //
  // n : string size.
  string longestPalindrome(const string& s) {
    int n = s.size();

    if (n == 0) return s;

    int at = 0;
    int size = 0;

    // Try all center position for the substr.
    for (int i = 0; i < n; ++i) {
      int extend = 0;
      // Expands as long as exists a palindrome of odd length.
      while (isPal(s, i - extend, i + extend)) {
        // Check if it is a better solution.
        if (2 * extend + 1 > size) {
          size = 2 * extend + 1;
          at = i - extend;
        }
        extend++;
      }

      extend = 0;
      // Expands as long as exists a palindrome of even length.
      while (isPal(s, i - extend, i + extend + 1)) {
        // Check if it is a better solution.
        if (2 * extend + 2 > size) {
          size = 2 * extend + 2;
          at = i - extend;
        }
        extend++;
      }
    }

    // Return the longest palindromic substring.
    return s.substr(at, size);
  }

  bool isPal(const string& s, int l, int r) {
    return l >= 0 && r < s.size() && s[l] == s[r];
  }
};
