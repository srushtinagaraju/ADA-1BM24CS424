#include <stdio.h>

int knapsack(int values[], int weights[], int n, int capacity) {
    int dp[n + 1][capacity + 1];
    
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= capacity; w++) {
            if (i == 0 || w == 0) {
                dp[i][w] = 0;
            } else if (weights[i - 1] <= w) {
                dp[i][w] = (dp[i - 1][w] > dp[i - 1][w - weights[i - 1]] + values[i - 1]) ? dp[i - 1][w] : dp[i - 1][w - weights[i - 1]] + values[i - 1];
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    return dp[n][capacity];
}

int main() {
    int values[] = {60, 100, 120};
    int weights[] = {10, 20, 30};
    int capacity = 50;
    int n = sizeof(values) / sizeof(values[0]);

    int max_value = knapsack(values, weights, n, capacity);

    printf("Maximum value in Knapsack = %d\n", max_value);
    
    return 0;
}


//OUTPUT:
Maximum value in Knapsack = 220
