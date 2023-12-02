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
    int n, q;
    cin >> n >> q;
    vector<vector<int>> vc(log2(n) +1, vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        cin >> vc[0][i];
    }
    for (int i = 1; i < log2(n) + 1; i++)
    {
        for (int j = 0; j + (1 << i) <= n; j++)
        {
            vc[i][j] = min(vc[i - 1][j], vc[i - 1][j + (1 << (i - 1))]);
        }
    }
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        l--, r--;
        int i = log2(r - l + 1);
        cout << min(vc[i][l], vc[i][r - (1 << i)+1]) << "\n";
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}