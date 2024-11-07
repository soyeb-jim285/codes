#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update>
void solve()
{
    string s;
    cin >> s;
    int n = s.size();
    int max= 1;
    int ct = 1;
    char c = s[0];
    for (int i = 1; i < n; i++)
    {
        if(s[i]==c)
        {
            ct++;
        }
        else{
            c = s[i];
            ct= 1;
        }
        if(ct > max)
        {
            max = ct;
        }
    }
    cout << max;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}