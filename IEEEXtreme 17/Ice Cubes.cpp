#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update>
#define ordered_pair_set tree<pair<ll, ll>, null_type, less<pair<ll, ll>>, rb_tree_tag, tree_order_statistics_node_update>
map<tuple<ll, ll, ll>, ll> mp;
ll fn(int i, int j, int k, int kk, int b, vector<vector<ll>> &vc)
{
    ll n = vc.size(), m = vc[0].size();
    
    ll kps = kk;
    if (mp[{i, j, kk}])
        return mp[{i, j, kk}];
    if (i == n - 1 && j == m - 1)
    {
        if (vc[i][j] < b)
            kk++;
        if (kk >= k)
            return -1e16;
        else
            return vc[i][j];
    }
    ll ans = -1e16;
    if (i + 1 < n)
    {
        ll ks = 0;
        if (vc[i][j] < b)
            kk++;
        else
            kk = 0;
        if (kk >= k)
            ks = -1e18;
        ans = max(ans, fn(i + 1, j, k, kk, b, vc) + vc[i][j] + ks);
    }
    if (j + 1 < m)
    {
        ll ks = 0;
        if (vc[i][j] < b)
            kk++;
        else
            kk = 0;
        if (kk >= k)
            ks = -1e18;
        ans = max(ans, fn(i, j + 1, k, kk, b, vc) + vc[i][j] + ks);
    }
    return mp[{i, j, kps}] = ans;
}
void solve()
{
    ll n, m, k, b;
    cin >> n >> m >> k >> b;
    vector<vector<ll>> vc(n, vector<ll>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> vc[i][j];
        }
    }
    if (fn(0, 0, k, 0, b, vc) > 0)
        cout << fn(0, 0, k, 0, b, vc) << "\n";
    else
        cout << "IMPOSSIBLE\n";
    mp.clear();
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t, tt = 1;
    cin >> t;
    while (t--)
    {
        cout << "Case " << tt++ << ": ";
        solve();
    }
    return 0;
}