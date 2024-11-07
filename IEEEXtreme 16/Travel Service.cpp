/*
    score = 100pt
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update>
#define ordered_pair_set tree<pair<ll, ll>, null_type, less<pair<ll, ll>>, rb_tree_tag, tree_order_statistics_node_update>
map<pair<ll, ll>, ll> mp;
ll fn(ll ind, ll wt, ll n, ll c, vector<pair<ll, ll>> &vc)
{
    if (ind > n - 1)
        return 0;
    if (mp[{ind, wt}])
        return mp[{ind, wt}];
    ll ww = wt - vc[ind + 1].first;
    ll rr = fn(ind + 1, c - vc[ind + 1].first, n, c, vc) + (c - wt) * vc[ind].second + 500;
    if (ww >= 0)
        rr = min(fn(ind + 1, ww, n, c, vc), rr);
    // cout << ind << " " << rr << "-\n";.
    return mp[{ind, wt}] = rr;
}
void solve()
{
    ll n, c, cost;
    cin >> n >> c >> cost;
    ll ans = cost * c;
    vector<pair<ll, ll>> vc(n);
    for (int i = 0; i < n; i++)
    {
        cin >> vc[i].first >> vc[i].second;
    }
    cout << fn(0, c - vc[0].first, n - 1, c, vc) + ans << "\n";
    mp.clear();
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}