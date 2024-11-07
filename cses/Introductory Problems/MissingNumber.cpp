#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update>
void solve()
{
    int n;
    cin >> n;
    vector<int> vc(n-1);
    for (int i = 0; i < n-1; i++)
    {
        cin >> vc[i];
    }
    sort(vc.begin(), vc.end());
    bool ch=0;
    for (int i = 0; i < n-1; i++)
    {
        if(vc[i]!=i+1)
        {
            ch=1;
            cout << i+1;
            break;
        }
    }
    if(!ch)
    {
        cout << n;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}