class Solution {
 public:
  // Time Complexity  = O(n * log(n) + n * log(k))
  // Space Complexity = O(k * log(k))
  //
  // n : nums size.
  // k : k most frequent numbers.
  vector<int> topKFrequent(vector<int>& nums, int k) {
    // Sort the input to get the frequency for each number. Might use a hash
    // (tradeoff).
    sort(nums.begin(), nums.end());

    int n = nums.size();

    // Priority queue to hold the top k most frequent numbers. The top holds the
    // less frequent number among the k most frequent numbers.
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>
       pq;

    int i = 0;
    while (i < n) {
      // Get the number frequency.
      int frequency = 0;
      while (i + 1 < n && nums[i] == nums[i + 1]) {
        i++; frequency++;
      }

      // Insert the number in the queue if there is no k numbers in the queue
      // yet, or if the number has a higher frequency than the less frequent
      // number in the queue, in this case remove this number from the queue.
      if (pq.size() < k) {
        pq.push({frequency, nums[i]});
      } else if (frequency > pq.top().first) {
        pq.pop();
        pq.push({frequency, nums[i]});
      }

      i++;
    }

    // Pop all elements in the heap and return them.
    vector<int> answer;
    while (!pq.empty()) {
      answer.push_back(pq.top().second);
      pq.pop();
    }

    return answer;
  }
};
