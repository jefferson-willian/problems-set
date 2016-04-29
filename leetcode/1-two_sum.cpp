class Solution {
 public:
  // Time Complexity  = O(n * h)
  // Space Complexity = O(n) 
  //
  // n : nums size.
  // h : hash lookup average complexity. O(1) best case and O(n) worst case.
  vector<int> twoSum(vector<int>& nums, int target) {
    // Hash the number value to its index in |nums|.
    unordered_map<int, int> hash;

    for (int i = 0; i < nums.size(); i++) {
      // Check if the remaining value of the sum is available in the hash. If
      // it exists then returns both values indexes.
      if (hash.find(target - nums[i]) != hash.end())
        return {hash[target - nums[i]], i};
      // Hash the number value to its index.
      hash[nums[i]] = i;
    }

    // Should never reach here.
  }
};
