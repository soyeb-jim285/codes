#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
void dfs(ll ver, ll &edg, vector<vector<ll>> &grp, vector<bool> &vis) {
  vis[ver] = true;
  edg++;
  for (auto &x : grp[ver]) {
    if (!vis[x])
      dfs(x, edg, grp, vis);
  }
}
void solve() {
  ll n, m;
  cin >> n >> m;
  vector<vector<ll>> grp(n + 1);
  vector<bool> vis(n + 1);
  for (int i = 0; i < m; i++) {
    ll u, v;
    cin >> u >> v;
    grp[u].push_back(v);
    grp[v].push_back(u);
  }
  ll ans = 0;
  for (int i = 1; i <= n; i++) {
    ll edg = 0;
    if (!vis[i])
      dfs(i, edg, grp, vis);
    ans += edg * (edg - 1) / 2;
  }
  ans -= m;
  cout << ans << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();
#ifdef ONPC
  cerr << endl
       << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif
}
