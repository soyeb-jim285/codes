#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update>
#define ordered_pair_set tree<pair<ll, ll>, null_type, less<pair<ll, ll>>, rb_tree_tag, tree_order_statistics_node_update>
void dfs(int i, int j, int &wtct, vector<vector<char>> &vc, vector<vector<bool>> &vis, set<pair<int, int>> &num, int n, int m)
{
    if (i < 0 || i >= n || j < 0 || j >= m)
        return;
    if (vis[i][j])
        return;
    if (vc[i][j] == 'B')
        return;
    else if (vc[i][j] == '.')
    {
        num.insert({i, j});
        return;
    }
    else
        wtct++;
    vis[i][j] = 1;
    dfs(i + 1, j, wtct, vc, vis, num, n, m);
    dfs(i, j + 1, wtct, vc, vis, num, n, m);
    dfs(i - 1, j, wtct, vc, vis, num, n, m);
    dfs(i, j - 1, wtct, vc, vis, num, n, m);
}
void solve()
{
    ll n, m;
    cin >> n >> m;
    vector<vector<char>> vc(n, vector<char>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> vc[i][j];
        }
    }
    cout << n << " " << m << "\n";
    for (auto ic : vc)
    {
        for (auto i : ic)
            cout << i;
        cout << "\n";
    }
    vector<vector<bool>> vis(n, vector<bool>(m));
    int ans = 0;
    map<pair<int, int>, int> mp;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            set<pair<int, int>> num;
            int wtct = 0;
            if (!vis[i][j] && vc[i][j] == 'W')
            {
                //dfs(i, j, wtct, vc, vis, num, n, m);
                // cout << num.size() << "\n";
            }
            if (num.size() == 1)
            {
                auto a = *num.begin();
                mp[a] += wtct;
            }
        }
    }
    for (auto ic : mp)
        ans = max(ans, ic.second);
    cout << ans << "\n";
}
int main()
{
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);
    //freopen64("meta_game_input.txt", "r", stdin);
    //freopen64("out.txt", "w", stdout);
    int t, tt = 1;
    cin >> t;
    while (t--)
    {
        cout << "Case #" << tt++ << ": ";
        solve();
    }
    return 0;
}