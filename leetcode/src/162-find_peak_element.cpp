class Solution {
 public:
  // Time Complexity  = O(log n)
  // Space Complexity = O(1)
  //
  // n : nums size.
  int findPeakElement(const vector<int>& nums) {
    return binSearch(nums, 0, nums.size());
  }

  int binSearch(const vector<int>& nums, int init, int end) {
    int mid = (end + init) / 2;

    // If the left subarray is in a increasing sequence then search in the
    // left subarray.
    if (mid > 0 && nums[mid - 1] > nums[mid])
      return binSearch(nums, init, mid);

    // If the right subarray is in a increasing sequence then search in the
    // right subarray.
    if (mid < nums.size() - 1 && nums[mid + 1] > nums[mid])
      return binSearch(nums, mid + 1, end);

    // Return mid as a index of the peak element.
    return mid;
  }
};
