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
    vector<ll> vc(n), ans;
    for (int i = 0; i < n; i++)
        cin >> vc[i];
    sort(vc.begin(), vc.end());
    ll a = vc.front(), b = vc.back();
    while (b > a)
    {
        ll x = 0;
        if (a % 2)
            x++;
        ans.push_back(x);
        a = (a + x) / 2;
        b = (b + x) / 2;
    }
    cout << ans.size() << "\n";
    if (ans.size() <= n)
    {
        for (auto ic : ans)
            cout << ic << " ";
        cout << "\n";
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