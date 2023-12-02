#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update>
#define ordered_pair_set tree<pair<ll, ll>, null_type, less<pair<ll, ll>>, rb_tree_tag, tree_order_statistics_node_update>
void dfs(ll ver, ll par, int dir, vector<pair<ll, ll>> &vc, vector<ll> &cost, string &s)
{
    cost[ver] = cost[par] + dir;
    if (vc[ver].first == 0 && vc[ver].second == 0)
        return;
    if (vc[ver].first >= 0)
    {
        if (s[ver] == 'L')
            dfs(vc[ver].first, ver, 0, vc, cost, s);
        else
            dfs(vc[ver].first, ver, 1, vc, cost, s);
    }
    if (vc[ver].second >= 0)
    {
        if (s[ver] == 'R')
            dfs(vc[ver].second, ver, 0, vc, cost, s);
        else
            dfs(vc[ver].second, ver, 1, vc, cost, s);
    }
}
void solve()
{
    ll n;
    cin >> n;
    string s;
    cin >> s;
    vector<pair<ll, ll>> vc(n);
    for (int i = 0; i < n; i++)
    {
        cin >> vc[i].first >> vc[i].second;
        vc[i].first--;
        vc[i].second--;
    }
    vector<ll> cost(n);
    dfs(0, 0, 0, vc, cost, s);
    //for(auto ic: cost)
    //cout << ic << " ";
    //cout << "\n";
    ll mn = 1e18;
    for (int i = 0; i < n; i++)
    {
        if (vc[i].first == -1 && vc[i].second == -1)
            mn = min(mn, cost[i]);
    }
    cout << mn << "\n";
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