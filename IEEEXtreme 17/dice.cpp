#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update>
#define ordered_pair_set tree<pair<ll, ll>, null_type, less<pair<ll, ll>>, rb_tree_tag, tree_order_statistics_node_update>
ll const mod = 998244353;
vector<ll> fact(1e7 + 1);
void fc()
{
    fact[0] = 1;
    for (int i = 1; i < 1e7 + 1; i++)
        fact[i] = (i * fact[i - 1]) % mod;
}
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
ll ncr(ll n, ll r)
{
    if (r > n)
        return 0;
    ll ans = fact[n];
    ll niche = (fact[r] * fact[n - r]) % mod;
    ans = (ans * binpowmod(niche, mod - 2, mod)) % mod;
    return ans;
}
void solve()
{
    ll n, kk;
    cin >> n >> kk;
    ll ans = 0;
    for (int i = 1; i <= min(kk, n); i++)
    {
        ll m = (n - i) / 6;
        ll val = 0;
        for (int k = 0; k <= m; k++)
        {
            ll lj = (ncr(i, k) * ncr(n - 6 * k - 1, i - 1)) % mod;
            // cout << lj << "\n";
            if (k % 2)
                val = (val - lj) % mod;
            else
                val = (val + lj) % mod;
            // cout << val << "\n";
        }
        ll niche = binpowmod(6, i, mod);
        val = (val * binpowmod(niche, mod - 2, mod)) % mod;
        ans = (ans + val) % mod;
    }
    ans = (ans * binpowmod(kk, mod - 2, mod)) % mod;
    if (ans < 0)
        ans += mod;
    cout << ans << "\n";
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    fc();
    solve();
    return 0;
}