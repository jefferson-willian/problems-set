class Solution {
 public:
  // Time Complexity  = O(n)
  // Space Complexity = O(n) 
  //
  // n : string size.
  string reverseVowels(string s) {
    // Left index pointer.
    int left = 0;
    // Right index pointer
    int right = s.size();

    // Return string.
    string ret = s;

    // Condition to process the string.
    while (left < right) {
      // Find a occurency of a vowel from left to right.
      while (left < right && !isVowel(ret[left])) left++;
      // Find a occurency of a vowel from right to left.
      while (left < right && !isVowel(ret[right - 1])) right--;
      // If the indexes pointers are valids then swap vowels.
      if (left < right) {
        swap(ret[left], ret[right - 1]);
        left++;
        right--;
      }
    }

    return ret;
  }

  // Check weather a character is a vowel (not case-sensitive).
  bool isVowel(char c) {
    switch (c) {
      case 'a':
      case 'e':
      case 'i':
      case 'o':
      case 'u':
      case 'A':
      case 'E':
      case 'I':
      case 'O':
      case 'U':
        return true;
      default:
        return false;
    }
  }
};
