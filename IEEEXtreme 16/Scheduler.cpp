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
ll const mod = 1e9 + 7;
ll binpowmod(ll a, ll b, ll m)
{
    ll res = 1;
    while (b > 0)
    {
        if (b & 1)
        {
            res *= a;
            res = res % m;
        }
        a *= a;
        a = a % m;
        b >>= 1;
    }
    return res;
}
void solve()
{
    ll n, k, sum = 0;
    cin >> n >> k;
    ll mx = 0;
    for (int i = 0; i < n; i++)
    {
        ll x;
        cin >> x;
        mx = max(x, mx);
        sum = (binpowmod(2, x, mod) + sum) % mod;
        if (sum < 0)
            sum += mod;
    }
    if (k == 1)
        cout << sum << "\n";
    else
        cout << binpowmod(2, mx, mod) << "\n";
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}