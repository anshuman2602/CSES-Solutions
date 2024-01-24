#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    multiset<int> s;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        s.insert(x);
    }
    for (int i = 0; i < m; i++)
    {
        int x;
        cin >> x;
        auto it = s.upper_bound(x);
        if (it == s.begin())
        {
            cout << "-1\n";
            continue;
        }
        it--;
        cout << *it << '\n';
        s.erase(it);
    }
    return 0;
}