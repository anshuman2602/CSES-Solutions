#include <bits/stdc++.h>
using namespace std;

struct ST
{
    vector<int> t;
    static const int inf = 1e9;
    ST(int _n)
    {
        t.assign(4 * _n, 0);
    }
    void build(vector<int> &a, int tidx, int st, int e)
    {
        if (st == e)
        {
            t[tidx] = a[st];
            return;
        }
        int mid = (st + e) >> 1, l = tidx << 1, r = l | 1;
        build(a, l, st, mid);
        build(a, r, mid + 1, e);
        t[tidx] = min(t[l], t[r]);
    }
    void upd(int tidx, int st, int e, int i, int x)
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
        t[tidx] = min(t[l], t[r]);
    }
    int query(int tidx, int st, int e, int i, int j)
    {
        if (st > j || e < i)
            return inf;
        if (st >= i && e <= j)
            return t[tidx];
        int mid = (st + e) >> 1, l = tidx << 1, r = l | 1;
        int L = query(l, st, mid, i, j);
        int R = query(r, mid + 1, e, i, j);
        return min(L, R);
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    ST st(n);
    st.build(a, 1, 0, n - 1);
    for (int i = 0; i < q; i++)
    {
        int op;
        cin >> op;
        if (op == 1)
        {
            int idx, val;
            cin >> idx >> val;
            --idx;
            st.upd(1, 0, n - 1, idx, val);
        }
        else
        {
            int l, r;
            cin >> l >> r;
            --l;
            --r;
            cout << st.query(1, 0, n - 1, l, r) << '\n';
        }
    }
    return 0;
}