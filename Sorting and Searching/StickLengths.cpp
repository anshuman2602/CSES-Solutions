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
    sort(a, a + n);
    ll ans1 = 0, ans2 = 0;
    for (int i = 0; i < n; i++)
    {
        ans1 += abs(a[i] - a[n / 2]);
        if (n > 1)
            ans2 += abs(a[i] - a[n / 2 + 1]);
    }
    cout << min(ans1, ans2);
    return 0;
}