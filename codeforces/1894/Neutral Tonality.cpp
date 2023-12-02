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
    ll n, m;
    cin >> n >> m;
    vector<ll> a(n);
    priority_queue<ll> b;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < m; i++)
    {
        ll x;
        cin >> x;
        b.push(x);
    }
    for (int i = 0; i < n; i++)
    {
        while (b.size())
        {
            ll fst = b.top();
            if (fst > a[i])
            {
                cout << fst << " ";
                b.pop();
            }
            else break;
        }
        cout << a[i] << " ";
    }
    while(b.size())
    {
        cout << b.top() << " ";
        b.pop();
    }
    cout << "\n";
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