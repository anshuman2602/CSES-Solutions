#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    int a[n], b[m];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < m; i++)
    {
        cin >> b[i];
    }
    sort(a, a + n);
    sort(b, b + m);
    int j = 0, ans = 0;
    for (int i = 0; i < n; i++)
    {
        while (j < m && b[j] < a[i] - k)
            j++;
        if (j < m && b[j] <= a[i] + k)
        {
            j++;
            ans++;
        }
    }
    cout << ans;
    return 0;
}