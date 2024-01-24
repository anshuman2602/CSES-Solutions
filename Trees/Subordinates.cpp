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
        int x;
        cin >> x;
        adj[x - 1].push_back(i + 1);
    }
 
    vector<int> ans(n);
    function<void(int)> solve = [&] (int u) -> void {
        for (auto &v : adj[u])
        {
            solve(v);
            ans[u] += 1 + ans[v] ;
        }
    };
 
    solve(0);
    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << ' ';
    }
    return 0;
}