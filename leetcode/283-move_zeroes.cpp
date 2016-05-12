class Solution {
 public:
  // Time Complexity  = O(n)
  // Space Complexity = O(1)
  //
  // n : nums size.
  void moveZeroes(vector<int>& nums) {
    int n = nums.size();

    // Position to write a number that is not a zero.
    int write = 0;

    // Iterate through all numbers and write those that aren't zeroes.
    for (int i = 0; i < n; ++i)
      if (nums[i] != 0)
        nums[write++] = nums[i];

    // Finishes to write the array with all zeroes.
    while (write < n) nums[write++] = 0;
  }
};
