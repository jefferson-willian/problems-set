class Solution {
 public:
  // Time Complexity  = O(n)
  // Space Complexity = O(1)
  //
  // n : nums size.
  int removeElement(vector<int>& nums, int val) {
    int n = nums.size();

    // Get the size of the new array.
    int size = 0;

    // Read all numbers and write to the new array only those numbers that are
    // different than |val|.
    for (int i = 0; i < n; ++i) {
      if (nums[i] == val)
        continue;
      nums[size++] = nums[i];
    }

    return size;
  }
};
