#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, x;
    cin >> n >> x;
    int price[n], pages[n];
    for (int i = 0; i < n; i++)
    {
        cin >> price[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> pages[i];
    }
    vector<int> dp(x + 1);
    for (int i = 0; i < n; i++)
    {
        for (int j = x; j > 0; j--)
        {
            if (j >= price[i])
                dp[j] = max(dp[j], dp[j - price[i]] + pages[i]);
        }
    }
    cout << dp[x];
    return 0;
}