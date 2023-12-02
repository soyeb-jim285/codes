#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<ll, null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update>
#define ordered_pair_set tree<pair<ll,ll>, null_type, less<pair<ll,ll>>, rb_tree_tag, tree_order_statistics_node_update>
void solve()
{
    ll a,b;
    cin >> b >> a;
    if(a > b)
    {
        if(a%2)
        {
            cout << a*a - b + 1 << "\n";
        }
        else{
            cout << (a-1) * (a-1) + b << "\n"; 
        }
    }
    else{
        if(b%2)
        {
            cout << (b-1)*(b-1) + a << "\n"; 
        }
        else{
            cout << b*b - a + 1 << "\n";
        }
        
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}