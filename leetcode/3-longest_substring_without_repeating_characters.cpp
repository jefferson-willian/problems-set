class Solution {
 public:
  // Time Complexity  = O(n)
  // Space Complexity = O(1)
  //
  // n : string size.
  int lengthOfLongestSubstring(string s) {
    size_t n = s.size();

    // Check weather the ascii character belongs to the current substring.
    vector<bool> ascii(128, false);

    // Substring initial position marker.
    int initial = 0;

    // Optimal substring size.
    int substr_size = 0;

    for (int i = 0; i < n; i++) {
      // If the ascii character isn't presented in the substring then just add
      // it.
      if (!ascii[s[i]]) {
        ascii[s[i]] = true;
      } else {
        // Loop all characters from the beginning of the substring and remove
        // them from the substring until the repeated character is reached.
        while (s[initial] != s[i]) ascii[s[initial++]] = false;
        // Move the initial marker one position after the repeated character.
        initial++;
      }
      // Check if we found the current optimal substring.
      substr_size = max(substr_size, i - initial + 1);
    }

    return substr_size;
  }
};
