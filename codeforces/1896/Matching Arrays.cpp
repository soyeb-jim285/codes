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
    vector<pair<ll, ll>> vc(n);
    vector<ll> b(n);
    for (int i = 0; i < n; i++)
    {
        ll x;
        cin >> x;
        vc[i] = {x, i};
    }
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }
    sort(vc.begin(), vc.end());
    //for (auto ic : vc)
    //    cout << ic.first << " ";
    //cout << "\n";
    sort(b.begin(), b.end());
    ll ck1 = 0;
    vector<ll> ans(n);
    ll p = n - x;
    for (int i = 0; i < n; i++)
    {
        ll ind = (i + n - x) % n;
        if (ind < 0)
            ind += n;
        ans[ind] = b[i];
        if (vc[ind].first > ans[ind])
            ck1++;
    }
    //for (auto ic : ans)
    //    cout
    //        << ic << " ";
    //cout << "\n";
    if (ck1 != x)
        cout << "NO\n";
    else
    {
        cout << "YES\n";
        vector<ll> mans(n);
        for (int i = 0; i < n; i++)
        {
            mans[vc[i].second] = ans[i];
        }
        for (auto ic : mans)
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