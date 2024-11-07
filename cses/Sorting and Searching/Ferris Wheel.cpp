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
    ll n, x;
    cin >> n >> x;
    multiset<ll> s;
    for (int i = 0; i < n; i++)
    {
        ll x;
        cin >> x;
        s.insert(x);
    }
    ll ans = 0;
    while(s.size())
    {
        ll a = *s.begin();
        if(a > x) break;
        s.erase(s.begin());
        ans++;
        auto ic = upper_bound(s.begin(), s.end(), x - a);
        if(ic!= s.begin())
        {
            ic--;
            s.erase(ic);
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