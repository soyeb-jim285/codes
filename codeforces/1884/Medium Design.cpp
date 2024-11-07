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
    ll n, m;
    cin >> n >> m;
    vector<pair<ll, ll>> vc;
    for (int i = 0; i < n; i++)
    {
        ll x, y;
        cin >> x >> y;
        vc.push_back({x, -1});
        vc.push_back({y, 1});
    }
    sort(vc.begin(), vc.end());
    ll kp = 0;
    ll mn = 0;
    for (int i = 0; i < vc.size(); i++)
    {
        kp += vc[i].second;
        if(kp < mn)
        {
            
        }
    }
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