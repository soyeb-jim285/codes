#include <bits/stdc++.h>
using namespace std;

#define sz(a) ((int)((a).size()))

typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
void bfs(ll ver, vector<ll> &dist, vector<vector<ll>> &grp) {
  ll n = sz(grp);
  vector<bool> vis(n);
  queue<ll> q;
  q.push(ver);
  ll mx_dist = 0;
  vis[ver] = true;
  while (!q.empty()) {
    ll u = q.front();
    q.pop();
    for (auto &v : grp[u]) {
      if (!vis[v]) {
        vis[v] = true;
        dist[v] = dist[u] + 1;
        q.push(v);
      }
    }
  }
}
void solve() {
  ll n, m;
  cin >> n >> m;
  vector<vector<ll>> grp(n + 1);
  for (int i = 0; i < m; i++) {
    ll u, v;
    cin >> u >> v;
    grp[u].push_back(v);
    grp[v].push_back(u);
  }
  vector<ll> dist1(n + 1), dist2(n + 1);
  ll a, b;
  cin >> a >> b;
  bfs(a, dist1, grp);
  bfs(b, dist2, grp);
  ll ans = 0, ind = -1;
  for (int i = 0; i < n; i++) {
    ans = max(ans, dist1[i] + dist2[i]);
  }
  cout << ans << "\n";
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
