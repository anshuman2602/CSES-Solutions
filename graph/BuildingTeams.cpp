#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        --u;
        --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> color(n, -1);
    vector<bool> vis(n);

    function<bool(int)> dfs = [&] (int u) {
        vis[u] = true;
        for (auto &v : adj[u])
        {
            if (!vis[v])
            {
                color[v] = 1 - color[u];
                if (!dfs(v))
                    return false;
            }
            else if (color[u] == color[v])
                return false;
        }
        return true;
    };

    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            color[i] = 0;
            if (!dfs(i))
            {
                cout << "IMPOSSIBLE";
                return 0;
            }
        }
    }
    for (auto &c : color)
    {
        cout << c + 1 << ' ';
    }
    return 0;
}