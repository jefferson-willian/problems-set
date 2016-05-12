class Solution {
 public:
  // Time Complexity  = O(n + m)
  // Space Complexity = O(1) 
  //
  // n : first array size.
  // m : second array size.
  void merge(vector<int>& nums1, int n, const vector<int>& nums2, int m) {
    // Shit all numbers from the first array to the end of the first array.
    for (int i = 0; i < n; ++i)
      nums1[n + m - 1 - i] = nums1[n - 1 - i];

    // Iterator to the first and second arrays.
    int l = m;
    int r = 0;

    for (int i = 0; i < n + m; ++i) {
      // Get the number from the first array if there is any number in the array
      // (l < n + m), and if the second array doesn't have any number (r >= m)
      // or if the lowest number in the first array is less or equal than the
      // lowest number from the second array.
      if (l < n + m && (r >= m || nums1[l] <= nums2[r]))
        nums1[i] = nums1[l++];
      else
        nums1[i] = nums2[r++];
    }
  }
};
