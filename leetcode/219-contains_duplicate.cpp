class Solution {
 public:
  // Time Complexity  = O(n * h)
  // Space Complexity = O(n)
  //
  // n : nums size.
  // h : hash lookup average complexity. O(1) best case and O(n) worst case.
  bool containsNearbyDuplicate(vector<int>& nums, int k) {
    int n = nums.size();

    // Store the number and the index in a hash table.
    unordered_map<int, int> hash;

    for (int i = 0; i < n; ++i) {
      // Get the current number in the hashtable.
      auto it = hash.find(nums[i]);

      // If it exists and there is a previous number that is no far from |k|
      // units, then return true;
      if (it != hash.end() && i - it->second <= k)
        return true;

      // Updates the number index.
      hash[nums[i]] = i;
    }

    return false;
  }
};
