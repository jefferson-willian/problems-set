class Solution {
 public:
  // Time Complexity  = O(num)
  // Space Complexity = O(num) 
  vector<int> countBits(int num) {
    // Return vector.
    vector<int> ret(num + 1, 0);

    // Assume that i is a number greater than zero and j is the number only with
    // the most significative digit in i, i.e.: if i = 10110 then j = 10000. So,
    // the number of 1s in i is given by the recursive function:
    //
    // f(i) = 1 + f(j)
    // f(1) = 1
    // f(0) = 0
    //
    int j = 1;
    for (int i = 1; i <= num; ++i) {
      // Updates j.
      if ((j & i) == 0) j <<= 1;
      // Calculate the number os 1s in |i|.
      ret[i] = ret[i - j] + 1;
    }

    return ret;
  }
};
