#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> dp(n + 1, 1e7);
    dp[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        int j = i;
        while (j > 0)
        {
            int d = j % 10;
            dp[i] = min(dp[i], dp[i - d] + 1);
            j /= 10;
        }
    }
    cout << dp[n];
    return 0;
}