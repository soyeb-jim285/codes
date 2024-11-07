#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update>
#define ordered_pair_set tree<pair<ll, ll>, null_type, less<pair<ll, ll>>, rb_tree_tag, tree_order_statistics_node_update>
ll const N = 2e5 + 5;
ll t[4 * N];
void build(vector<ll> &vc, int v, int tl, int tr)
{
    if (tl == tr)
        t[v] = vc[tl];
    else
    {
        int tm = (tl + tr) >> 1;
        build(vc, 2 * v, tl, tm);
        build(vc, 2 * v + 1, tm + 1, tr);
        t[v] = (t[2 * v] ^ t[2 * v + 1]);
    }
}
void update(int v, int tl, int tr, int pos, ll new_val)
{
    if (tl == tr)
        t[v] = new_val;
    else
    {
        int tm = (tl + tr) >> 1;
        if (pos <= tm)
            update(2 * v, tl, tm, pos, new_val);
        else
            update(2 * v + 1, tm + 1, tr, pos, new_val);
        t[v] = min(t[2 * v], t[2 * v + 1]);
    }
}
ll xr(int v, int tl, int tr, int l, int r)
{
    if (l > r)
        return 0;
    else if (tl == l && tr == r)
        return t[v];
    else
    {
        int tm = (tl + tr) >> 1;
        return (xr(2 * v, tl, tm, l, min(r, tm)) ^ xr(2 * v + 1, tm + 1, tr, max(l, tm + 1), r));
    }
}
void solve()
{
    ll n, q;
    cin >> n >> q;
    vector<ll> vc(n);
    for (int i = 0; i < n; i++)
        cin >> vc[i];
    build(vc, 1, 0, n - 1);
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        l--, r--;
        cout << xr(1, 0, n - 1, l, r) << "\n";
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}