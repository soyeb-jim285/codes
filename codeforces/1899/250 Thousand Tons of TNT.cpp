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
    ll n;
    cin >> n;
    ll fst = 0, lst= 0, ans = 0;
    vector<ll> vc(n);
    for (int i = 0; i < n; i++)
    {
        cin >> vc[i];
    }
    sort(vc.begin(), vc.end());
    for (int i = 1; i <= n/2; i++)
    {
        fst += vc[i-1];
        lst += vc[n-i];
        if(n%i == 0)
        {
            ans = max(lst-fst, ans);
        }
    }
    
    cout << ans<< "\n";
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
/*
1 2 3 3 6 10 
*/