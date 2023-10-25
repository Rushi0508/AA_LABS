#include <bits/stdc++.h>

using namespace std;

int knapsack(vector<int> &values, vector<int> &weights, int capacity)
{
    int n = values.size();
    vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, 0));

    // Build the dynamic programming table
    for (int i = 1; i <= n; i++)
    {
        for (int w = 1; w <= capacity; w++)
        {
            // If the current item can fit in the knapsack
            if (weights[i - 1] <= w)
            {
                // Decide whether to include the current item or not
                dp[i][w] = max(dp[i - 1][w], dp[i - 1][w - weights[i - 1]] + values[i - 1]);
            }
            else
            {
                // If the current item is too heavy, exclude it
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    // The result is stored in dp[n][capacity]
    return dp[n][capacity];
}

void sum_of_subset(vector<int> arr, int sum)
{

    int m = arr.size();
    vector<int> p(m), w(m);

    for (int i = 0; i < m; i++)
    {
        p[i] = arr[i];
        w[i] = arr[i];
    }

    int ans = knapsack(p, w, sum);

    // cout << ans << " ";

    if (sum == ans)
        cout << "we can have sum of " << sum << endl;
    else
        cout << "we can't have sum of " << sum << endl;
}

int main()
{
    int n;
    cout << "Enter the number of items: ";
    cin >> n;

    vector<int> values(n);

    cout << "Enter the values of items: ";
    for (int i = 0; i < n; i++)
        cin >> values[i];

    int capacity;
    cout << "Enter the knapsack capacity: ";
    cin >> capacity;

    sum_of_subset(values, capacity);

    return 0;
}