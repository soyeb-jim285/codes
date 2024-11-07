#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
ll const N = 1e5 + 1;
vector<vector<ll>> grp(N);
vector<bool> vis(N);
vector<ll> par(N);
ll bg, ed;
bool dfs(int var, int parr) {
  par[var] = parr;
  vis[var] = true;
  for (auto child : grp[var]) {
    if (child == parr)
      continue;
    if (vis[child]) {
      ed = child;
      bg = var;
      return true;
    } else {
      if (dfs(child, var))
        return true;
    }
  }
  return false;
}
void solve() {
  ll n, m;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    ll u, v;
    cin >> u >> v;
    grp[u].push_back(v);
    grp[v].push_back(u);
  }
  for (int i = 0; i < n; i++) {
    if (!vis[i] && dfs(i, -1)) {
      vector<ll> ans;
      ans.push_back(ed);
      while (ed != bg) {
        ans.push_back(bg);
        bg = par[bg];
      }
      ans.push_back(ed);
      cout << ans.size() << endl;
      for (auto x : ans) {
        cout << x << " ";
      }
      return;
    }
  }
  cout << "IMPOSSIBLE";
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
