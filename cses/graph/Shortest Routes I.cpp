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
  ll n, m;
  cin >> n >> m;
  vector<vector<pair<ll, ll>>> grp(n + 1);
  vector<ll> dist(n + 1, INF);
  for (int i = 0; i < m; i++) {
    ll u, v, w;
    cin >> u >> v >> w;
    grp[u].push_back({v, w});
    // grp[v].push_back({u, w});
  }
  dijkstra(1, grp, dist);
  for (int i = 0; i < n; i++) {
    cout << dist[i + 1] << " ";
  }
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
