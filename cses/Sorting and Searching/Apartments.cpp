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
    vector<ll> vc(n), vc2(m);
    for (int i = 0; i < n; i++)
        cin >> vc[i];
    for (int i = 0; i < m; i++)
        cin >> vc2[i];
    sort(vc.begin(), vc.end());
    sort(vc2.begin(), vc2.end());
    ll ans = 0;
    int i = 0,j= 0;
    //for(auto ic: vc)
    //cout << ic << " ";
    //cout << "\n";
    //for(auto ic: vc2)
    //cout << ic << " ";
    //cout << "\n";
    while(i<n && j<m)
    {
        //cout << vc[i] << " " << vc2[j] << "\n";
        if(abs(vc[i] - vc2[j]) <= k)
        {
            ans++;
            i++;
            j++;
            //cout << "bla\n";
        }
        else{
            if(vc[i] > vc2[j])
                j++;
            else
                i++;
        }
    }
    cout << ans << "\n";
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}