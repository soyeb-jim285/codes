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
    ll n, ans = 0;
    cin >> n;
    vector<ll> vc(n), cost(n);
    for (int i = 0; i < n; i++)
        cin >> vc[i];
    cost[0] = vc[0]-1;
    for (int i = 1; i < n; i++)
    {
        if (vc[i - 1] >= vc[i])
            cost[i] = cost[i - 1];
        else
            cost[i] = cost[i - 1] + (vc[i] - vc[i-1]);
    }
    cout << cost.back() << "\n";
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