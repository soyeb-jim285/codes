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
    string s;
    cin >> s;
    map<char, int> mp;
    for (int i = 0; i < s.size(); i++)
    {
        mp[s[i]]++;
    }
    string ans = "";
    char a;
    bool ck = 0;
    for (auto ic : mp)
    {
        if (ic.second % 2)
        {
            if (ck)
            {
                cout << "NO SOLUTION\n";
                return;
            }
            ck = 1;
            a = ic.first;
        }
        for (int i = 0; i < ic.second / 2; i++)
        {
            ans += ic.first;
        }
    }
    cout << ans;
    if(ck) cout << a;
    reverse(ans.begin(), ans.end());
    cout << ans << "\n";
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}