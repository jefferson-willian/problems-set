class Solution {
 public:
  // Time Complexity  = O(n)
  // Space Complexity = O(1)
  //
  // n : nums size.
  void rotate(vector<int>& nums, int k) {
    int n = nums.size();

    // Don't need to rotate more than, or equal, the size of the array.
    k = k % n;

    // Reverse entire array and then the first |k| numbers and the last |n - k|
    // numbers.
    reverse(nums, 0, n);
    reverse(nums, 0, k);
    reverse(nums, k, n);
  }

  void reverse(vector<int>& nums, int init, int end) {
    for (int i = 0; i < (end - init) / 2; ++i)
      swap(nums[init + i], nums[end - 1 - i]);
  }
};
