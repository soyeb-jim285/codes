#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update>
#define ordered_pair_set tree<pair<ll, ll>, null_type, less<pair<ll, ll>>, rb_tree_tag, tree_order_statistics_node_update>
ll const mod = 998244353;
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
    ll k, n;
    cin >> k >> n;
    vector<ll> fact(n + 1);
    vector<ll> ans(binpowmod(2, k, mod));
    fact[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        fact[i] = (i * fact[i - 1]) % mod;
    }
    for (int i = 0; i <= n; i++)
    {
        ll t = i % binpowmod(2, k, mod);
        ll val = fact[n];
        ll nice = (fact[i] * fact[n - i]) % mod;
        val = (val * binpowmod(nice, mod - 2, mod)) % mod;
        ans[t] += val;
    }
    for (auto ic : ans)
        cout << ic << " ";
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}