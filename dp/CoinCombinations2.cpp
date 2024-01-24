#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, x;
    cin >> n >> x;
    int coins[n];
    for (int i = 0; i < n; i++)
    {
        cin >> coins[i];
    }
    vector<int> dp(x + 1);
    dp[0] = 1;
    int m = 1e9 + 7;
    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j <= x; j++)
        {
            if (j >= coins[i])
                dp[j] = (dp[j] + dp[j - coins[i]]) % m;
        }
    }
    cout << dp[x];
    return 0;
}