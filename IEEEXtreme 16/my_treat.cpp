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
void solve()
{
    ll n;
    cin >> n;
    map<string, pair<int, int>> mp;
    for (int i = 0; i < n; i++)
    {
        string x;
        cin >> x;
        ll nn;
        cin >> nn;
        mp[x].first+=nn;
        while (nn--)
        {
            string xx;
            cin >> xx;
            mp[xx].second++;
        }
    }
    ll mx = 0, sum = 0;
    for (auto ic : mp)
    {
        //cout << ic.first << " " << ic.second.first << " " << ic.second.second << "\n";
        ll m = ic.second.first - ic.second.second;
        mx = max(mx, m);
        sum += abs(ic.second.first - ic.second.second);
        //cout << ic.second.first - ic.second.second << "\n";
    }
    cout << sum / 2 << " " << mx << "\n";
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