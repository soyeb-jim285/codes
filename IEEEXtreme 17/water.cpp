#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<long long int, null_type, less<long long int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
typedef tree<long long int, null_type, less_equal<long long int>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;

typedef long long int ll;
typedef long double ld;
typedef queue<ll> ql;
typedef vector<ll> vl;
typedef vector<pair<ll, ll>> vll;
typedef vector<pair<ll, pair<ll, ll>>> vp;
typedef vector<vector<ll>> vvl;
typedef vector<char> vc;
typedef vector<bool> vb;
typedef vector<string> vs;
#define f(i, g, h) for (long long int i = g; i < h; i++)
const long long int md = 1000000007;

ll binpow(ll x, ll y)
{
    // cout << x << " " << y << " " << res << endl;
    ll res = 1;
    while (y > 0)
    {
        if (y % 2)
        {
            res *= x % md;
            res %= md;
        }
        x = (x * x) % md;
        y /= 2;
    }
    return res % md;
}
//---------------------------------------------------------------------------------------------------------------------------

void solve()
{
    ll n, m;
    cin >> n >> m;
    vvl h(n, vl(m));
    vector<vector<long double>> w(n, vector<long double>(m));
    vector<vll> a(10000001);
    ll mx = 0;
    set<ll> smx;
    map<ll, vector<pair<int, int>>> mp;
    f(i, 0, n)
    {
        f(j, 0, m)
        {
            cin >> h[i][j];
            w[i][j] = 1.0;
            smx.insert(h[i][j]);
            mp[h[i][j]].push_back({i, j});
        }
    }
    while (smx.size())
    {
        int i = *--smx.end();
        smx.erase(--smx.end());
        f(j, 0, mp[i].size())
        {
            ll x = mp[i][j].first;
            ll y = mp[i][j].second;
            ll k = 0;
            if (x > 0)
                if (h[x][y] > h[x - 1][y])
                    k++;
            if (x < (n - 1))
                if (h[x][y] > h[x + 1][y])
                    k++;
            if (y > 0)
                if (h[x][y] > h[x][y - 1])
                    k++;
            if (y < (m - 1))
                if (h[x][y] > h[x][y + 1])
                    k++;
            if (k > 0)
            {
                ld p = w[x][y] / (k * 1.0);
                if (x > 0)
                    if (h[x][y] > h[x - 1][y])
                        w[x - 1][y] += p;
                if (x < (n - 1))
                    if (h[x][y] > h[x + 1][y])
                        w[x + 1][y] += p;
                if (y > 0)
                    if (h[x][y] > h[x][y - 1])
                        w[x][y - 1] += p;
                if (y < (m - 1))
                    if (h[x][y] > h[x][y + 1])
                        w[x][y + 1] += p;
            }
        }
    }
    ld mn = 0.0;
    f(i, 0, n)
    {
        f(j, 0, m)
        {
            mn = max(mn, w[i][j]);
        }
    }
    cout << mn << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t = 1;
    cout << setprecision(16);
    // cin >> t;
    while (t--)
        solve();
    return 0;
}