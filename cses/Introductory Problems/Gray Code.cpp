#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update>
#define ordered_pair_set tree<pair<ll, ll>, null_type, less<pair<ll, ll>>, rb_tree_tag, tree_order_statistics_node_update>
ll binpow(ll a, ll b)
{
    ll res = 1;
    while (b > 0)
    {
        if (b & 1)
            res *= a;
        a *= a;
        b >>= 1;
    }
    return res;
}
ll g(ll n){
    return n ^ (n >> 1);}
string dectobin(ll n, ll sz)
{
    string ans = "";
    while (n)
    {
        if (n % 2)
            ans += '1';
        else
            ans += '0';
        n /= 2;
    }
    while (ans.size() < sz)
        ans += '0';
    reverse(ans.begin(), ans.end());
    return ans;
}
void solve()
{
    int n;
    cin >> n;
    const unsigned int nn = n;
    ll a = binpow(2, n);
    for (int i = 0; i < a; i++)
        cout << dectobin(g(i), n) << "\n";
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}