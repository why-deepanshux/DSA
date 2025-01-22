#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int knapsack(vector<int>& weight, vector<int>& value, int n, int W ,vector<vector<int>>&dp) {
    // Base condition
    if (n == 0 || W == 0) {
        return 0;
    }

    if(dp[n][W]!=-1)return dp[n][W];


    // Choice diagram
    if (weight[n - 1] <= W) {
        // Include the item or skip it
        return dp[n][W]=max(
            value[n - 1] + knapsack(weight, value, n - 1, W - weight[n - 1],dp),
            knapsack(weight, value, n - 1, W,dp)
        );
    }

    // Skip the item
    return dp[n][W]=knapsack(weight, value, n - 1, W,dp);
}

int main() {
    int W;  // Maximum weight of the knapsack
    cin >> W;

    int n;  // Number of items
    cin >> n;

    vector<int> weight(n), value(n);
    for (int i = 0; i < n; i++) {
        cin >> weight[i] >> value[i];
    }
    // make a matrix to memoize the problem
    vector<vector<int>> dp(n+1, vector<int>(W+1,-1));
    // Printing maximum profit
    int maxProfit = knapsack(weight, value, n, W,dp);
    cout << maxProfit;

    return 0;
}
