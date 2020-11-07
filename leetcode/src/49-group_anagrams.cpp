class Solution {
 public:
  // Time Complexity  = O(n * m * log(m + n))
  // Space Complexity = O(m * n) 
  //
  // n : number of strings.
  // m : size of the longest string.
  vector<vector<string>> groupAnagrams(vector<string>& strs) {
    int n = strs.size();

    // Group of anagrams.
    vector<vector<string>> group;

    // Hold distinct anagrams.
    set<pair<string, int>> anagrams;

    for (int i = 0; i < n; ++i) {
      // Get the current string and the current string sorted.
      string sorted_str = strs[i];
      sort(sorted_str.begin(), sorted_str.end());

      // Get the lower bound of the sorted string in the set of anagrams.
      auto it = anagrams.lower_bound({sorted_str, -1});

      // Check if the anagram exists, if it doesn't then create it.
      if (it != anagrams.end() && it->first == sorted_str) {
        group[it->second].emplace_back(strs[i]);
      } else {
        anagrams.insert({sorted_str, group.size()});
        group.emplace_back(vector<string>(1, strs[i]));
      }
    }

    // Sort the inner anagrams.
    for (int i = 0; i < group.size(); i++)
      sort(group[i].begin(), group[i].end());

    return group;
  }
};
