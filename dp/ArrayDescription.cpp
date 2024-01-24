#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int mod = 1e9 + 7;
    vector<vector<int>> dp(n, vector<int>(m + 1));
    for (int i = 1; i <= m; i++)
    {
        if (a[0] == 0)
            dp[0][i] = 1;
        else
            dp[0][i] = (i == a[0] ? 1 : 0);
    }
    for (int i = 1; i < n; i++)
    {
        if (a[i] == 0)
        {
            for (int j = 1; j <= m; j++)
            {
                for (int x : {j - 1, j, j + 1})
                {
                    if (x >= 1 && x <= m)
                        dp[i][j] = (dp[i][j] + dp[i - 1][x]) % mod;
                }
            }
        }
        else
        {
            for (int j : {a[i] - 1, a[i], a[i] + 1})
            {
                if (j >= 1 && j <= m)
                    dp[i][a[i]] = (dp[i][a[i]] + dp[i - 1][j]) % mod;
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= m; i++)
    {
        ans = (ans + dp[n - 1][i]) % mod;
    }
    cout << ans;
    return 0;
}