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
    ll sum = (n * (n + 1)) / 2;
    if (sum % 2)
        cout << "NO\n";
    else
    {
        cout << "YES\n";
        ll a = 0, b = 0;
        vector<ll> vca, vcb;
        for (int i = n; i >= 1; i--)
        {
            if (a < b)
            {
                vca.push_back(i);
                a += i;
            }
            else
            {
                vcb.push_back(i);
                b += i;
            }
        }
        cout << vca.size() << "\n";
        for (auto ic : vca)
            cout << ic << " ";
        cout << "\n";
        cout << vcb.size() << "\n";
        for (auto ic : vcb)
            cout << ic << " ";
        cout << "\n";
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}