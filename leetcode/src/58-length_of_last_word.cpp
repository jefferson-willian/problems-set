class Solution {
 public:
  // Time Complexity  = O(n)
  // Space Complexity = O(1) 
  //
  // n : string size.
  int lengthOfLastWord(const string& s) {
    int size = 0;

    // Ignore all empty spaces at the end of the string.
    int i = s.size() - 1;
    while (i >= 0 && s[i] == ' ') --i;

    // Count the characters of the last word.
    while (i >= 0 && s[i] != ' ') {
      i--;
      size++;
    }

    return size;
  }
};
