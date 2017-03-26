class Solution {
 public:
  // Time Complexity  = O(n)
  // Space Complexity = O(1)
  //
  // n : height size.
  int maxArea(vector<int>& height) {
    // Initial solution.
    int solution = 0;

    // Starts using the widest possible container.
    int i = 0;
    int j = height.size() - 1;

    while (i < j) {
      // Update solution.
      solution = max(solution, (j - i) * min(height[i], height[j]));

      // Greedy choice, remove the smallest side.
      height[i] < height[j] ? i++ : j--;
    }

    return solution;
  }
};
