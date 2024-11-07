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
    ll n, m, k;
    cin >> n >> m >> k;
    vector<string> vc(n);
    for (int i = 0; i < n; i++)
    {
        cin >> vc[i];
        string tmp = "";
        for (int j = 0; j < m; j++)
        {
            for (int jj = 0; jj < k; jj++)
            {
                tmp += vc[i][j];
            }
        }
        for (int j = 0; j < k; j++)
        {
            cout << tmp << "\n";
        }
        
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen64("cowsignal.in", "r", stdin);
    freopen64("cowsignal.out", "w", stdout);
    solve();
    return 0;
}