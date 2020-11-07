class Solution {
 public:
  // Time Complexity  = O(n)
  // Space Complexity = O(1)
  //
  // n : nums size.
  int majorityElement(vector<int>& nums) {
    int n = nums.size();

    int counter = 0;
    int number = -1;

    for (int i = 0; i < n; ++i) {
      // If the number if the majority number or if the counter is zero then
      // we can update the majority number.
      if (nums[i] == number || counter == 0)
        number = nums[i];

      // Increases the counter if the number is the current majority number
      // or decreases if the number is not the current majority number.
      counter += nums[i] == number ? 1 : -1;
    }

    // Return the majority number.
    return number;
  }
};
