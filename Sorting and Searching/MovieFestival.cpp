#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<pair<int, int>> v;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        v.emplace_back(b, a);
    }
    sort(v.begin(), v.end());
    int prevEnd = -1, ans = 0;
    for (auto [e, s] : v)
    {
        if (prevEnd <= s)
        {
            ans++;
            prevEnd = e;
        }
    }
    cout << ans;
    return 0;
}