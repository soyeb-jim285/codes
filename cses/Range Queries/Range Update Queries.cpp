#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update>
#define ordered_pair_set tree<pair<ll, ll>, null_type, less<pair<ll, ll>>, rb_tree_tag, tree_order_statistics_node_update>
ll const N = 2e5 + 10;
vector<ll> t(4 * N);
void build(vector<ll> &vc, ll v, ll tl, ll tr)
{
    if (tl == tr)
        t[v] = vc[tl];
    else
    {
        ll tm = (tl + tr) >> 1;
        build(vc, 2 * v, tl, tm);
        build(vc, 2 * v + 1, tm + 1, tr);
        t[v] = 0;
    }
}
void update(ll v, ll tl, ll tr, ll l, ll r, ll val)
{
    if (l > r)
        return;
    if (l == tl && r == tr)
        t[v] += val;
    else
    {
        ll tm = (tl + tr) >> 1;
        update(2 * v, tl, tm, l, min(r, tm), val);
        update(2 * v + 1, tm + 1, tr, max(l, tm+1), r, val);
    }
}
ll get(ll v, ll tl, ll tr, ll pos)
{
    if (tl == tr)
        return t[v];
    ll tm = (tl + tr) >> 1;
    if (pos <= tm)
        return t[v] + get(2 * v, tl, tm, pos);
    else
        return t[v] + get(2 * v + 1, tm + 1, tr, pos);
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
        ll x;
        cin >> x;
        if (x == 1)
        {
            ll l, r, val;
            cin >> l >> r >> val;
            l--;
            r--;
            update(1, 0, n - 1, l, r, val);
        }
        else
        {
            ll pos;
            cin >> pos;
            pos--;
            cout << get(1, 0, n - 1, pos) << "\n";
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}