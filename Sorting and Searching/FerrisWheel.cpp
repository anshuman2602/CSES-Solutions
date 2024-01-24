#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, x;
    cin >> n >> x;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a, a + n);
    int j = 0, ans = n;
    for (int i = n - 1; i > j; i--)
    {
        if (a[i] + a[j] <= x)
        {
            ans--;
            j++;
        }
    }
    cout << ans;
    return 0;
}