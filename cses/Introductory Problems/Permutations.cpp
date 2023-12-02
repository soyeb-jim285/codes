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
    if(n==1) cout << "1";
    else if(n<4)
    {
        cout << "NO SOLUTION";
    }
    else if(n==4)
    {
        cout << "3 1 4 2";
    }
    else{
        for (int i = 0; i < n; i+=2)
        {
            cout << i+1 << " ";
        }
        for (int i = 0; i < n-1; i+=2)
        {
            cout << i+2 << " ";
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}