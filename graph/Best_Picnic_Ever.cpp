#include <bits/stdc++.h>
#include <ios>
using namespace std;

#define sz(a) ((int)((a).size()))

typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
void dfs(ll ver, vector<ll> &gese, vector<bool> &vis, vector<vector<ll>> &grp) {
  vis[ver] = true;
  gese[ver]++;
  for (auto &i : grp[ver]) {
    if (!vis[i]) {
      dfs(i, gese, vis, grp);
    }
  }
}
void solve() {
  ll k, n, m;
  cin >> k >> n >> m;
  vector<ll> pr(k);
  for (auto &i : pr) {
    cin >> i;
  }
  vector<ll> gese(n + 1);
  vector<bool> vis(n + 1);
  vector<vector<ll>> grp(n + 1);
  for (int i = 0; i < m; i++) {
    ll u, v;
    cin >> u >> v;
    grp[u].push_back(v);
  }
  for (int i = 0; i < pr.size(); i++) {
    for (int i = 0; i < vis.size(); i++) {
      vis[i] = false;
    }
    dfs(pr[i], gese, vis, grp);
  }
  ll ans = 0;
  for (int i = 1; i <= n; i++) {
    if (gese[i] == k) {
      ans++;
    }
  }
  cout << ans << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t, tt = 1;
  cin >> t;
  while (t--) {
    cout << "Case " << tt++ << ": ";
    solve();
  }
#ifdef ONPC
  cerr << endl
       << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif
}
