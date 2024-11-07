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
    ll n, m, ans = 0;
    cin >> n >> m;
    priority_queue<ll> q;
    for (int i = 0; i < n; i++)
    {
        ll x;
        cin >> x;
        q.push(x);
    }
    vector<multiset<ll>> vc(m);
    vector<map<ll, int>> vk(m);
    while (q.size())
    {
        ll a = q.top();
        bool ck = 0;
        if (!vc[0].size())
        {
            vc[0].insert(a);
            vk[0][a]++;
            q.pop();
            ans = (ans + binpowmod(2, a, mod)) % mod;
            if (ans < 0)
                ans += mod;
            ck = 1;
        }
        else
            for (int i = 0; i < m - 1; i++)
            {
                if (!vc[i + 1].size())
                {
                    vc[i + 1].insert(a);
                    vk[i + 1][a]++;
                    ck = 1;
                    q.pop();
                    while (vk[i + 1][a] > 1)
                    {
                        vk[i + 1][a] = 0;
                        vc[i + 1].erase(a);
                        a++;
                        vk[i + 1][a]++;
                        vc[i + 1].insert(a);
                    }
                    break;
                }
                else if (*--vc[i].end() > *--vc[i + 1].end())
                {
                    vc[i + 1].insert(a);
                    vk[i + 1][a]++;
                    ck = 1;
                    q.pop();
                    while (vk[i + 1][a] > 1)
                    {
                        vk[i + 1][a] = 0;
                        vc[i + 1].erase(a);
                        a++;
                        vk[i + 1][a]++;
                        vc[i + 1].insert(a);
                    }
                    break;
                }
            }
        if (!ck)
        {
            for (int i = 0; i < m; i++)
            {
                vk[i][*--vc[i].end()] = 0;
                vc[i].erase(*--vc[i].end());
            }
        }
    }
    cout << ans << "\n";
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}