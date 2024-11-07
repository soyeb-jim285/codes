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
    ll a, b, c;
    cin >> a >> b >> c;
    bool aa = 0, bb = 0, cc = 0;
    if ((a - b) % 2 == 0)
        cc = 1;
    if ((b - c) % 2 == 0)
        aa = 1;
    if ((a - c) % 2 == 0)
        bb = 1;
    cout << aa << " " << bb << " " << cc << "\n";
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