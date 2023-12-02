#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update>
#define ordered_pair_set tree<pair<ll, ll>, null_type, less<pair<ll, ll>>, rb_tree_tag, tree_order_statistics_node_update>
void solve()
{
    ll n, m, sm = 0;
    cin >> n >> m;
    vector<ll> a(100), b(100);
    for (int i = 0; i < n; i++)
    {
        ll x, y;
        cin >> x >> y;
        for (int j = 0; j < x; j++)
        {
            a[j + sm] = y;
        }
        sm += x;
    }
    sm = 0;
    for (int i = 0; i < m; i++)
    {
        ll x, y;
        cin >> x >> y;
        for (int j = 0; j < x; j++)
        {
            b[j + sm] = y;
        }
        sm += x;
    }
    ll mx = 0;
    for (int i = 0; i < 100; i++)
    {
        mx = max(mx, b[i]-a[i]);
    }
    cout << mx << "\n";
}
int main()
{
    freopen64("speeding.in", "r", stdin);
    freopen64("speeding.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}