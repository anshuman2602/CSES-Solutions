#include <bits/stdc++.h>
using namespace std;
#define ll long long int

struct ST
{
    vector<ll> t;
    static const int inf = 1e9;
    ST(int _n)
    {
        t.assign(4 * _n, 0);
    }

    void build(vector<ll> &a, int tidx, int st, int e)
    {
        if (st == e)
        {
            t[tidx] = a[st];
            return;
        }
        int mid = (st + e) >> 1, l = tidx << 1, r = l | 1;
        build(a, l, st, mid);
        build(a, r, mid + 1, e);
        t[tidx] = t[l] + t[r];
    }

    void upd(int tidx, int st, int e, int i, ll x)
    {
        if (st > i || e < i)
            return;
        if (st == e && st == i)
        {
            t[tidx] = x;
            return;
        }
        int mid = (st + e) >> 1, l = tidx << 1, r = l | 1;
        upd(l, st, mid, i, x);
        upd(r, mid + 1, e, i, x);
        t[tidx] = t[l] + t[r];
    }

    ll query(int tidx, int st, int e, int i, int j)
    {
        if (st > j || e < i)
            return 0;
        if (st >= i && e <= j)
            return t[tidx];
        int mid = (st + e) >> 1, l = tidx << 1, r = l | 1;
        ll L = query(l, st, mid, i, j);
        ll R = query(r, mid + 1, e, i, j);
        return L + R;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    vector<ll> a(n), b(n + 1);
    for (auto &x : a)
    {
        cin >> x;
    }
    ST st(n + 1);
    st.build(b, 1, 0, n);
    for (int i = 0; i < q; i++)
    {
        int op;
        cin >> op;
        if (op == 1)
        {
            int l, r, v;
            cin >> l >> r >> v;
            l--;
            b[l] += v;
            b[r] -= v;
            st.upd(1, 0, n, l, b[l]);
            st.upd(1, 0, n, r, b[r]);
        }
        else
        {
            int idx;
            cin >> idx;
            idx--;
            cout << a[idx] + st.query(1, 0, n, 0, idx) << '\n';
        }
    }
    return 0;
}