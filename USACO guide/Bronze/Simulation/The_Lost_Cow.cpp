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
    ll k = m - n;
    if (k == 0)
    {
        cout << 0 << "\n";
        return;
    }
    if (k > 0)
    {
        ll x = 1, pw = 0;
        while (x < k)
        {
            x *= 4;
            pw += 2;
        }
        //cout << x << " " << pw << "\n";
        ll ans = 2 * ((1 << pw) - 1) + (1 << pw);
        cout << ans - (x - k) << "\n";
    }
    else
    {
        k *= -1;
        ll x = 2, pw = 1;
        while (x < k)
        {
            x *= 4;
            pw += 2;
        }
        ll ans = 2 * ((1 << pw) - 1) + (1 << pw);
        cout << ans - (x - k) << "\n";
    }
}
int main()
{
    freopen64("lostcow.in", "r", stdin);
    freopen64("lostcow.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}