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


    vector<int> dist(n, -1);
    vector<int> parent(n);
    dist[0] = 0;
    parent[0] = -1;
    queue<int> q;
    q.push(0);
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (auto &v : adj[u])
        {
            if (dist[v] == -1)
            {
                dist[v] = dist[u] + 1;
                parent[v] = u;
                q.push(v);
            }
        }
    }

    if (dist[n - 1] == -1)
    {
        cout << "IMPOSSIBLE";
        return 0;
    }
    
    cout << dist[n - 1] + 1 << '\n';
    vector<int> path;
    int x = n - 1;
    while (x != -1)
    {
        path.push_back(x);
        x = parent[x];
    }
    reverse(path.begin(), path.end());
    for (auto &x : path)
    {
        cout << x + 1 << ' ';
    }
    return 0;
}