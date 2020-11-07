class Solution {
 public:
  // Time Complexity  = O(n)
  // Space Complexity = O(n) 
  //
  // n : string size.
  int numDecodings(const string& s) {
    int n = s.size();

    if (n == 0) return 0;

    // dp[i] holds the total number of ways to decode the substring that
    // starts at position i.
    vector<int> dp(n + 1, 1);

    // Initial dynamic programming answer.
    dp[n - 1] = s[n - 1] == '0' ? 0 : 1;

    for (int i = n - 2; i >= 0; --i) {
      // If the character is 0 then puts 0 because it is not a valid
      // substring.
      if (s[i] == '0') {
        dp[i] = 0;
        continue;
      }

      // Get the number using two characters.
      int num = (s[i] - '0') * 10 + s[i + 1] - '0';

      // Get the answer for the substring that starts at position i.
      if (num <= 26)
        dp[i] = dp[i + 1] + dp[i + 2];
      else
        dp[i] = dp[i + 1];
    }

    return dp[0];
  }
};
