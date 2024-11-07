#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update>
#define ordered_pair_set tree<pair<ll, ll>, null_type, less<pair<ll, ll>>, rb_tree_tag, tree_order_statistics_node_update>
ll fn(ll ind, ll sum, vector<ll> &vc, vector<ll> &pre)
{
    ll n = vc.size();
    if (ind >= n)
        return 0;
    ll ans = fn(ind + 1, sum, vc, pre);
    //cout << ans << " ";
    if (abs(fn(ind + 1, sum, vc, pre)  + vc[ind] - pre[ind]) < abs(ans - pre[ind]))
        ans = fn(ind + 1, sum , vc, pre) + vc[ind];
    //cout << ans << " " << ind << "\n";
    return ans;
}
void solve()
{
    ll n;
    cin >> n;
    vector<ll> vc(n), pre(n);
    for (int i = 0; i < n; i++)
        cin >> vc[i];
    pre[0] = vc[0];
    for (int i = 1; i < n; i++)
        pre[i] = pre[i-1] + vc[i];
    
    //sort(vc.begin(), vc.end());
    cout << abs(fn(0, 0, vc, pre) - pre[n-1]) << "\n";
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}