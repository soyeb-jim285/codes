#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
void dijkstra(ll s, vector<ll> &ver_weight, vector<vector<pair<ll, ll>>> &adj,
              vector<ll> &dis, vector<ll> &parent) {
  ll n = ver_weight.size();
  dis[s] = ver_weight[s];
  set<pair<ll, ll>> q;
  q.insert({dis[s], s});
  while (!q.empty()) {
    ll v = q.begin()->second;
    q.erase(q.begin());
    for (auto edge : adj[v]) {
      ll to = edge.first;
      ll len = edge.second;
      if (dis[v] + len + ver_weight[to] < dis[to]) {
        q.erase({dis[to], to});
        dis[to] = dis[v] + len + ver_weight[to];
        parent[to] = v;
        q.insert({dis[to], to});
      }
    }
  }
}
void solve() {
  ll n, m;
  cin >> n >> m;
  vector<ll> ver_weight(n), dis(n, 1e15), parent(n, -1);
  for (ll i = 0; i < n; i++) {
    cin >> ver_weight[i];
  }
  vector<vector<pair<ll, ll>>> adj(n);
  for (int i = 0; i < m; i++) {
    ll u, v, w;
    cin >> u >> v >> w;
    adj[u - 1].push_back({v - 1, w});
    adj[v - 1].push_back({u - 1, w});
  }
  dijkstra(0, ver_weight, adj, dis, parent);
  for (ll i = 1; i < n; i++) {
    cout << dis[i] << " ";
  }
  cout << "\n";
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
