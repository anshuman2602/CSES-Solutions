#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        --u;
        --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<vector<int>> dp(n, vector<int>(2));
    function<void(int, int)> solve = [&] (int u, int par) -> void {
        dp[u][0] = dp[u][1] = 0;
        bool leaf = true;
        for (auto &v : adj[u])
        {
            if (v != par)
            {
                leaf = false;
                solve(v, u);
            }
        }
        if (leaf)
            return;
        for (auto &v : adj[u])
        {
            if (v != par)
                dp[u][0] += max(dp[v][0], dp[v][1]);
        }
        for (auto &v : adj[u])
        {
            if (v != par)
                dp[u][1] = max(dp[u][1], 1 + dp[u][0] - max(dp[v][0], dp[v][1]) + dp[v][0]);
        }
    };

    solve(0, -1);
    cout << max(dp[0][0], dp[0][1]);
    return 0;
}