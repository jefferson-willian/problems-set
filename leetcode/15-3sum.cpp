class Solution {
 public:
  // Time Complexity  = O(n ^ 2)
  // Space Complexity = O(n)
  //
  // n : nums size.
  vector<vector<int>> threeSum(vector<int>& nums) {
    // Get a sorted copy from input.
    vector<int> temp = nums;
    sort(temp.begin(), temp.end());

    // Solution vector.
    vector<vector<int>> solution;

    // Fix a number and find other two.
    for (int i = 0; i < temp.size(); ++i) {
      // Fix a distinct number every time.
      if (i > 0 && temp[i] == temp[i - 1]) continue;

      // Set two indices two find the two other numbers.
      int j = i + 1;
      int k = temp.size() - 1;

      // Find two other numbers to complete the equation a + b + c = 0
      while (j < k) {
        int total = temp[i] + temp[j] + temp[k];
        // Check if the equation was satisfied or if it needs to increase or
        // decrease the total value of the two other numbers.
        if (total == 0) {
          // Add to the solution.
          solution.push_back({temp[i], temp[j], temp[k]});
          // Get two different numbers.
          do j++; while (j < k && temp[j - 1] == temp[j]);
          do k--; while (k > j && temp[k + 1] == temp[k]);
        } else if (total < 0) {
          // Increase the total value of the two numbers.
          j++;
        } else {
          // Decrease the total value of the two numbers.
          k--;
        }
      }
    }

    return solution;
  }
};
