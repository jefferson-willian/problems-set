class Solution {
 public:
  // Time Complexity  = O(log n)
  // Space Complexity = O(1)
  //
  // n : nums size.
  int findMin(const vector<int>& nums) {
    return nums[binSearch(nums, 0, nums.size())];
  }

  int binSearch(const vector<int>& nums, int init, int end) {
    // If we found the subarray that starts the sorted sequence then return
    // the index of the first number.
    if (nums[init] <= nums[end - 1]) return init;

    // Get the middle element.
    int mid = (init + end) / 2;

    // If the middle element is in a increasing subsequence then the rotation
    // point is in the right part of the subarray, otherwise the rotation
    // point is in the left part of the subarray.
    if (nums[init] < nums[mid])
      return binSearch(nums, mid + 1, end);
    else
      return binSearch(nums, init + 1, mid + 1);
  }
};
