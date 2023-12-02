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
    vector<ll> vc(n);
    for (int i = 0; i < n; i++)
    {
        cin >> vc[i];
    }
    sort(vc.begin(), vc.end());
    ll x = 0, ans = 0;
    for (int i = 0; i < n - 1; i++)
    {
        if (x + vc[i] > vc[i + 1])
        {
            ll a = (vc[i] - x) / 2;
            ans += a;
            ans++;
            x += a;
            vc[i] -= (x + a);
            x = vc[i];
            ans += vc[i];
        }
        else
        {
            x += vc[i];
            ans += vc[i];
        }
    }
    if (vc[n - 1])
    {
        ll a = (vc[n - 1] - x) / 2;
        ans += a;
        cout << ans<< " " << a << " " << x << "-\n";
        x += a;
        ans++;
        cout << ans << "--\n";
        vc[n - 1] -= (x + a);
        x = vc[n - 1];
        ans += vc[n - 1];
        cout << ans << "---\n";
        cout << a << " " << x << " " << vc[n - 1] << "\n";
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
/*
x + a = vc - a
2a = vc - x
a =
*/