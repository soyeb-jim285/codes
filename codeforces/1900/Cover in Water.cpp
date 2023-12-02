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
    string s;
    cin >> s;
    ll ans = 0, ln = 0, mx = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '.')
        {
            ln++;
        }
        else
        {
            ans += ln;
            mx = max(ln, mx);
            ln = 0;
        }
    }
    if (ln)
    {
        ans += ln;
        mx = max(ln, mx);
    }
    if (mx > 2)
        ans = 2;
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