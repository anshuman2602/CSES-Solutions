#include <bits/stdc++.h>
using namespace std;
#define ll long long int
 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    ll a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    vector<ll> pref(n + 1);
    for (int i = 0; i < n; i++)
    {
        pref[i + 1] = pref[i] ^ a[i];
    }
    for (int i = 0; i < q; i++)
    {
        int l, r;
        cin >> l >> r;
        cout << (pref[r] ^ pref[l - 1]) << '\n';
    }
    return 0;
}