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
    ll n, q, one = 0, two = 0;
    cin >> n >> q;
    vector<ll> vc(n);
    for (int i = 0; i < n; i++)
    {
        cin >> vc[i];
        if (vc[i] == 1)
            one++;
        else
            two++;
    }
    while (q--)
    {
        ll x, y;
        cin >> x >> y;
        if (x == 1)
        {
            if (2 * two + one < y)
                cout << "1NO\n";
            if (2 * two <= y)
            {
                ll p = y - 2 * two;
                if (one >= p)
                    cout << "YES\n";
                else
                    cout << "3NO\n";
            }
            else
            {
                ll pp = y / 2;
                ll p = y - pp * 2;
                //cout << pp << " " << p << " " << one << "--\n";
                if (one >= p)
                    cout << "YES\n";
                else
                    cout << "4NO\n";
            }
        }
        else
        {
            ll z;
            cin >> z;
            if (vc[x - 1] == 1)
            {
                one--;
                vc[x - 1] = z;
                if (z == 1)
                    one++;
                else
                    two++;
            }
            else
            {
                two--;
                vc[x - 1] = z;
                if (z == 1)
                    one++;
                else
                    two++;
            }
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