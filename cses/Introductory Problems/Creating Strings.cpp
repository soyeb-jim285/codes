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
    sort(s.begin(), s.end());
    vector<string> ans;
    ans.push_back(s);
    while (next_permutation(s.begin(), s.end()))
    {
        ans.push_back(s);
    }
    cout << ans.size() << "\n";
    for(auto ic: ans)
    cout << ic << "\n";
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}