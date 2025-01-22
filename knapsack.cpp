#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int knapsack(vector<int>& weight, vector<int>& value, int n, int W) {
    // Base condition
    if (n == 0 || W == 0) {
        return 0;
    }

    // Choice diagram
    if (weight[n - 1] <= W) {
        // Include the item or skip it
        return max(
            value[n - 1] + knapsack(weight, value, n - 1, W - weight[n - 1]),
            knapsack(weight, value, n - 1, W)
        );
    }

    // Skip the item
    return knapsack(weight, value, n - 1, W);
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

    // Printing maximum profit
    int maxProfit = knapsack(weight, value, n, W);
    cout << maxProfit;

    return 0;
}
