#include <bits/stdc++.h>
using namespace std;

#define sz(a) ((int)((a).size()))

typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
void dfs(ll ver, vector<vector<pair<ll, ll>>> &grp, vector<bool> &vis,
         vector<ll> &dis) {
  vis[ver] = true;
  for (auto child : grp[ver]) {
    if (!vis[child.first]) {
      dis[child.first] = dis[ver] + child.second;
      dfs(child.first, grp, vis, dis);
    }
  }
}
void solve() {
  ll n;
  cin >> n;
  vector<vector<pair<ll, ll>>> grp(n);
  vector<bool> vis(n);
  vector<ll> dis(n);
  for (int i = 0; i < n - 1; i++) {
    ll u, v, w;
    cin >> u >> v >> w;
    grp[u].push_back({v, w});
    grp[v].push_back({u, w});
  }
  ll mx = 0, mxv = 0;
  dfs(0, grp, vis, dis);
  for (int i = 0; i < n; i++) {
    if (dis[i] > mx) {
      mx = dis[i];
      mxv = i;
    }
  }
  for (int i = 0; i < n; i++) {
    dis[i] = 0;
    vis[i] = false;
  }
  dfs(mxv, grp, vis, dis);
  for (int i = 0; i < n; i++) {
    if (dis[i] > mx) {
      mx = dis[i];
    }
  }
  cout << mx << "\n";
}
int main() {
  ios::sync_with_stdio(false);
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
