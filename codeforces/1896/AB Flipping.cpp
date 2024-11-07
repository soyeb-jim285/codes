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
    ll n, inda = -1, indb = -1;
    bool ck = 0;
    cin >> n;
    string s;
    cin >> s;
    ll ans = -1;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'A' && ck == 0)
        {
            inda = i;
            ck = 1;
        }
        if (s[i] == 'B')
            indb = i;
    }
    if(inda == -1 || indb == -1)
    {
        cout << "0\n";
    }
    else{
        cout << max(indb - inda, 0LL) << "\n";
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