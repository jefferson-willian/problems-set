class Solution {
 public:
  // Time Complexity  = O(n)
  // Space Complexity = O(1) 
  //
  // n : prices size.
  int maxProfit(const vector<int>& prices) {
    int n = prices.size();

    // Hold the best profit.
    int profit = 0;

    // Hold the best day to buy.
    int best_min = INT_MAX;

    for (int i = 0; i < n; ++i) {
      // Check if it is better to buy on day ith.
      best_min = min(best_min, prices[i]);

      // Check if it is better to sell on day ith.
      profit = max(profit, prices[i] - best_min);
    }

    return profit;
  }
};
