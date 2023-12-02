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
    map<ll, ll> mp;
    for (int i = 0; i < n; i++)
    {
        cin >> vc[i];
        mp[vc[i]]++;
    }
    vector<ll> boro;
    for (auto ic : mp)
    {
        if (ic.second > 1)
            boro.push_back(ic.first);
    }
    if (boro.size() <= 1)
        cout << "-1\n";
    else
    {
        ll a = boro[0], b = boro[1];
        bool aa = 0, bb = 0;
        for (int i = 0; i < n; i++)
        {
            if (vc[i] == a && aa == 0)
            {
                cout << "2 ";
                aa = 1;
            }
            else if (vc[i] == b && bb == 0)
            {
                cout << "3 ";
                bb = 1;
            }
            else cout << "1 ";
        }
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