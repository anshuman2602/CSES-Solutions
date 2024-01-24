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
    vector<bool> vis(n);
    vector<int> compHead;
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            compHead.push_back(i);
            queue<int> q;
            q.push(i);
            vis[i] = true;
            while (!q.empty())
            {
                int u = q.front();
                q.pop();
                for (auto &v : adj[u])
                {
                    if (!vis[v])
                    {
                        vis[v] = true;
                        q.push(v);
                    }
                }
            }
        }
    }
    int k = compHead.size();
    cout << k - 1 << '\n';
    for (int i = 0; i < k - 1; i++)
    {
        cout << compHead[i] + 1 << ' ' << compHead[i + 1] + 1 << '\n';
    }
    return 0;
}