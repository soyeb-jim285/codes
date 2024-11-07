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
    vector<string> id(n+1); 
    for (int i = 0; i < n; i++)
        cin >> vc[i];
    for (int i = 0; i < n; i++)
        cin >> id[i+1];
    for (int i = 0; i < 3; i++)
    {
        vector<ll> tmp(n);
        for (int j = 0; j < n; j++)
        {
            tmp[vc[j]-1] = j+1;
        }
        vc = tmp;
    }
    for(auto ic: vc)
    cout << id[ic] << "\n";
}
int main()
{
    freopen64("shuffle.in", "r", stdin);
    freopen64("shuffle.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}