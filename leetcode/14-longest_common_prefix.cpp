class Solution {
 public:
  // Time Complexity  = O(n * m)
  // Space Complexity = O(m) 
  //
  // n : total os strings.
  // m : size of the shortest string.
  string longestCommonPrefix(const vector<string>& strs) {
    int n = strs.size();

    // Prefix string.
    string prefix;

    // Return empty string if there is no input strings.
    if (n == 0) return prefix;

    // Get the size of the shortest string.
    int m = strs[0].size();
    for (int i = 0; i < n; ++i)
      m = min(m, (int)strs[i].size());

    for (int j = 0; j < m; ++j) {
      // If it is not a common prefix in all input strings, then there is no
      // way to expand the prefix.
      for (int i = 1; i < n; ++i)
        if (strs[0][j] != strs[i][j])
          return prefix;

      // Expand the prefix.
      prefix.push_back(strs[0][j]);
    }

    return prefix;
  }
};
