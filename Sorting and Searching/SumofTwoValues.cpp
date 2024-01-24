#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, x;
    cin >> n >> x;
    map<int, int> m;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        if (m.count(x - a[i]))
        {
            cout << m[x - a[i]] + 1 << ' ' << i + 1;
            return 0;
        }
        m[a[i]] = i;
    }
    cout << "IMPOSSIBLE";
    return 0;
}