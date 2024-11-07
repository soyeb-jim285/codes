#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
ll const INF = 1e18;
void dijkstra(ll s, vector<vector<pair<ll, ll>>> &grp, vector<ll> &dist) {
  priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> q;
  q.push({0, s});
  dist[s] = 0;
  while (q.size()) {
    auto [d, u] = q.top();
    q.pop();
    if (d != dist[u])
      continue;
    for (auto [v, w] : grp[u]) {
      if (dist[u] + w < dist[v]) {
        dist[v] = dist[u] + w;
        q.push({dist[v], v});
      }
    }
  }
}
void solve() {
  ll n, m, q;
  cin >> n >> m >> q;
  vector<vector<pair<ll, ll>>> grp(n + 1);
  vector<vector<ll>> d(n + 1, vector<ll>(n + 1, INF));
  for (int i = 0; i < m; i++) {
    ll u, v, w;
    cin >> u >> v >> w;
    grp[u].push_back({v, w});
    grp[v].push_back({u, w});
    d[u][v] = min(d[u][v], w);
    d[v][u] = min(d[v][u], w);
  }
  for (int i = 1; i <= n; i++) {
    d[i][i] = 0;
  }
  for (int k = 1; k <= n; ++k) {
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= n; ++j) {
        d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
      }
    }
  }
  // for (int i = 0; i < n; i++) {
  //   dijkstra(i + 1, grp, dist[i + 1]);
  //   // cout << i + 1 << "-----\n";
  //   // for (auto ic : dist[i + 1]) {
  //   //   cout << ic << " ";
  //   // }
  //   // cout << "\n";
  // }
  while (q--) {
    ll u, v;
    cin >> u >> v;
    if (d[u][v] == INF) {
      cout << -1 << endl;
    } else {
      cout << d[u][v] << endl;
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#ifdef ONPC
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  solve();
#ifdef ONPC
  cerr << endl
       << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif
}
