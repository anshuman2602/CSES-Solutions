#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    map<int, int> m;
    for (int i = 0; i < n; i++)
    {
        int l, r;
        cin >> l >> r;
        m[l]++;
        m[r + 1]--;
    }
    ll sum = 0, ans = 0;
    for (auto &x : m)
    {
        sum += x.second;
        ans = max(ans, sum);
    }
    cout << ans;
    return 0;
}