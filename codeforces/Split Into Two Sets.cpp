#include <bits/stdc++.h>
using namespace std;

#define sz(a) ((int)((a).size()))

typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
void dfs(int ver, vector<vector<ll>> &grp, vector<bool> &vis, vector<ll> &tmp) {
  vis[ver] = true;
  tmp.push_back(ver);
  for (auto &x : grp[ver]) {
    if (vis[x])
      continue;
    dfs(x, grp, vis, tmp);
  }
  return;
}
void solve() {
  ll n;
  cin >> n;
  vector<vector<ll>> grp(n + 1);
  vector<ll> cnt(n + 1);
  bool ok = true;
  for (int i = 0; i < n; i++) {
    ll u, v;
    cin >> u >> v;
    cnt[u]++;
    cnt[v]++;
    if (cnt[u] > 2 || cnt[v] > 2)
      ok = false;
    grp[u].push_back(v);
    grp[v].push_back(u);
  }
  if (!ok) {
    cout << "NO\n";
    return;
  }
  vector<bool> vis(n + 1, false);
  vector<ll> tmp;
  for (int i = 0; i < n; i++) {
    if (!vis[i + 1]) {
      dfs(i + 1, grp, vis, tmp);
      if (tmp.size() % 2) {
        cout << "NO\n";
        return;
      }
    }
  }
  cout << "YES\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--)
    solve();
#ifdef ONPC
  cerr << endl
       << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif
}
