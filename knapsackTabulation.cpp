#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int knapsack(vector<int>& weight, vector<int>& value, int n, int W, vector<vector<int>>& dp) {
    // Initialize DP table (Base case: dp[i][0] = 0 and dp[0][j] = 0)
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= W; j++) {
            dp[i][j] = 0;
        }
    }

    // Fill the DP table iteratively
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= W; j++) {
            if (weight[i - 1] <= j) { // Can we include the current item?
                dp[i][j] = max(
                    value[i - 1] + dp[i - 1][j - weight[i - 1]], // Include item
                    dp[i - 1][j]                                // Exclude item
                );
            } else {
                dp[i][j] = dp[i - 1][j]; // Exclude item
            }
        }
    }

    // Return the maximum profit for n items and capacity W
    return dp[n][W];
}

int main() {
    int W; // Maximum weight of the knapsack
    cin >> W;

    int n; // Number of items
    cin >> n;

    vector<int> weight(n), value(n);
    for (int i = 0; i < n; i++) {
        cin >> weight[i] >> value[i];
    }

    // DP table to store intermediate results
    vector<vector<int>> dp(n + 1, vector<int>(W + 1));

    // Compute and print the maximum profit
    int maxProfit = knapsack(weight, value, n, W, dp);
    cout << maxProfit;

    return 0;
}
