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
    vector<ll> vc(n - 1);
    ll xxr = 0, allxr = n - 1;
    for (int i = 0; i < n - 1; i++)
    {
        cin >> vc[i];
        allxr = allxr ^ i;
        if (i % 2)
            xxr = xxr ^ vc[i];
    }
    ll fst;
    if (n % 2)
        fst = allxr ^ xxr;
    else
    {
        for (int i = 0; i < n; i++)
        {
            ll x = (i ^ xxr) ^ allxr;
            if (x <= n - 1 && x >= 0)
            {
                fst = i;
                break;
            }
        }
    }
    cout << fst << " ";
    for (int i = 0; i < n - 1; i++)
    {
        fst = vc[i] ^ fst;
        cout << fst << " ";
    }
    cout << "\n";
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}