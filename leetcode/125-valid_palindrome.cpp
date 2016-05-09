class Solution {
 public:
  // Time Complexity  = O(n)
  // Space Complexity = O(1) 
  //
  // n : string size.
  bool isPalindrome(const string& s) {
    // Left and right indicators.
    int left = 0;
    int right = s.size() - 1;

    // Necessary condition to check if a palindrome is invalid.
    while (left < right) {
      // Seek for valid characters.
      while (left < right && !isAlphaNum(s[left])) left++;
      while (left < right && !isAlphaNum(s[right])) right--;

      // If the characters are different then it is certain that it is not a
      // palindrome.
      if (left < right && !isEqual(s[left], s[right]))
        return false;

      // Update indicators.
      left++;
      right--;
    }

    return true;
  }

  char toLower(char c) {
    if (c >= 'A' && c <= 'Z')
      return c - 'A' + 'a';
    else
      return c;
  }

  bool isAlphaNum(char c) {
    if (c >= 'a' && c <= 'z') return true;
    if (c >= 'A' && c <= 'Z') return true;
    if (c >= '0' && c <= '9') return true;
    return false;
  }

  bool isEqual(char a, char b) {
    return toLower(a) == toLower(b);
  }
};
