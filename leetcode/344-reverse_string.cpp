class Solution {
 public:
  // Time Complexity  = O(n)
  // Space Complexity = O(n) 
  //
  // n : string size.
  string reverseString(string s) {
    // Copy the return string.
    string ret = s;

    // String size.
    int n = s.size();

    // Swap the first letter and the last letter, the second letter and the
    // second last letter and so on until we reach the middle of string. If we
    // do this for the whole string then we gonna reverse it two times, ending
    // up with the original string.
    for (int i = 0; i < n / 2; i++) 
      swap(ret[i], ret[n - 1 - i]);

    return ret;
  }
};
