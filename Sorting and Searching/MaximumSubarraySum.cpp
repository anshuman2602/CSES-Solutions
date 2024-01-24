#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    ll ans = a[0], mxeh = 0;
    for (int i = 0; i < n; i++)
    {
        mxeh = max(mxeh + a[i], (ll)a[i]);
        ans = max(ans, mxeh);
    }
    cout << ans;
    return 0;
}