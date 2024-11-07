#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update>
#define ordered_pair_set tree<pair<ll, ll>, null_type, less<pair<ll, ll>>, rb_tree_tag, tree_order_statistics_node_update>
void solve()
{
    ld a;
    cin >> a;
    ll ct = 1;
    ld mn = 3;
    ll ans = 1;
    while (1)
    {
        ld val = cos(1.0 * a * ct * M_PI / 180);
        if(abs(val) < mn)
        {
            ans = ct;
            mn = abs(val);
        }
        ct++;
        if (ct > 1e6)
            break;
    }
    cout << ans << "\n";
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