#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update>
#define ordered_pair_set tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>
vector<int> last_greater_element(vector<int> &a)
{
    vector<int> ans;
    stack<int> st;

    for (int x : a)
    {
        while (!st.empty() && st.top() <= x)
            st.pop();

        if (st.empty())
            ans.push_back(-1);
        else
            ans.push_back(st.top());

        st.push(x);
    }
    return ans;
}
void solve()
{
    ll n, h, a, c, q;
    cin >> n >> h >> a >> c >> q;
    vector<int> vc = {29, 17, 16, 21, 19, 40, 3, 14, 8};
    // vc[0] = h;
    // for (int i = 1; i < n; i++)
    //{
    //     vc[i] = (vc[i - 1] * a + c) % q;
    //     if (vc[i] < 0)
    //         vc[i] += q;
    // }
    vector<int> val = last_greater_element(vc);
    val[2] = 29;
    for (auto ic : val)
        cout << ic << " ";
    cout << "\n";
    map<ll, ll> mp;
    mp[-1] = -1;
    int ans = 0, ct = 1, p = mp[val[0]] + 1;
    for (int i = 1; i < vc.size(); i++)
    {
        if (vc[i] < vc[i - 1])
        {
            ans += ct + p;
            mp[vc[i]] = mp[val[i]] + 1;
            ct++;
        }
        else
        {
            ans += ct + p;
            mp[vc[i]] = mp[val[i]] + 1;
            p = mp[val[i]] + 1;
            ct = 1;
        }
        cout << ans << " " << i << " " << p << "\n";
    }
    for (auto ic : mp)
        cout << ic.first << " " << ic.second << "\n";
    cout << ans << "\n";
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
/*
5,  4, 2, 1, 2, 3,  6
-1, 5, 4, 2, 4, 4, -1
0   1  2  3  4  3   3
*/