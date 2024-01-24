#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<string> grid(n);
    for (int i = 0; i < n; i++)
    {
        cin >> grid[i];
    }
    int m = 1e9 + 7;
    vector<vector<int>> dp(n, vector<int>(n, 1));
    bool r = false, c = false;
    for (int i = 0; i < n; i++)
    {
        if (grid[i][0] == '*')
            c = true;
        if (grid[0][i] == '*')
            r = true;
        if (r)
            dp[0][i] = 0;
        if (c)
            dp[i][0] = 0;
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < n; j++)
        {
            if (grid[i][j] == '*')
                dp[i][j] = 0;
            else
            {
                dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % m;
            }
        }
    }
    cout << dp[n - 1][n - 1];
    return 0;
}