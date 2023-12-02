#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update>
void solve()
{
    long long n;
    cin >> n;
    vector<long long> vc(n);
    long long sum =0;
    long long max = 0;
    cin >> vc[0];
    long long f = vc[0];
    for (int i = 1; i < n; i++)
    {
        cin >> vc[i];
        if(f>vc[i])
        {
            sum+= (f-vc[i]);
            //cout << "sum = " << sum << "\n";
        }
        else{
            f = vc[i];
        }
    }
    cout << sum ;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}