#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<vector<int>> adj(n);
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        --u;
        --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> depth(n);
    vector<vector<int>> dp(n, vector<int>(2));
    function<void(int, int)> solve = [&] (int u, int par) -> void {
        bool leaf = true;
        depth[u] = 1;
        for (auto &v : adj[u])
        {
            if (v != par)
            {
                leaf = false;
                solve(v, u);
                depth[u] = max(depth[u], 1 + depth[v]);
            }
        }
        if (leaf)
            return;
        int mx1 = 0, mx2 = 0;
        for (auto &v : adj[u])
        {
            if (v != par)
            {
                dp[u][0] = max(dp[u][0], max(dp[v][0], dp[v][1]));
                if (depth[v] > mx1)
                {
                    mx2 = mx1;
                    mx1 = depth[v];
                }
                else if (depth[v] > mx2)
                    mx2 = depth[v];
            }
        }
        dp[u][1] += mx1 + mx2;
    };

    solve(0, -1);
    cout << max(dp[0][0], dp[0][1]);
    return 0;
}