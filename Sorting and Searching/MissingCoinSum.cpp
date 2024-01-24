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
    ll curr = 1;
    for (int i = 0; i < n; i++)
    {
        if (curr < a[i])
            break;
        curr += a[i];
    }
    cout << curr;
    return 0;
}