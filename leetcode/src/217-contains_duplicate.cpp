class Solution {
 public:
  // Time Complexity  = O(n * h)
  // Space Complexity = O(n)
  //
  // n : nums size.
  // h : hash lookup average complexity. O(1) best case and O(n) worst case.
  bool containsDuplicate(vector<int>& nums) {
    int n = nums.size();

    // A hash to tell if a number exists in the array.
    unordered_map<int, bool> hash;

    for (int i = 0; i < n; ++i) {
      // If the number exists in the array then it contains duplicate.
      if (hash.find(nums[i]) != hash.end())
        return true;

      // Insert the number in the hash.
      hash[nums[i]] = true;
    }

    return false;
  }
};
