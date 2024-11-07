#include <bits/stdc++.h>
#include <vector>
using namespace std;
typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
ll const INF = 1e18;
struct Edge {
  ll a, b, cost;
  bool operator<(const Edge &e) const { return cost < e.cost; }
};
ll const N = 2500 + 1;
vector<ll> d(N, INF);
bool neg_cyc(ll v, ll n, vector<Edge> &edges) {
  d[v] = 0;
  vector<ll> p(n, -1);
  int x;
  for (int i = 0; i < n; ++i) {
    x = -1;
    for (Edge e : edges)
      if (d[e.a] < INF)
        if (d[e.b] > d[e.a] + e.cost) {
          d[e.b] = max(-INF, d[e.a] + e.cost);
          p[e.b] = e.a;
          x = e.b;
        }
  }

  if (x == -1) {
    return false;
  } else {
    int y = x;
    for (int i = 0; i < n; ++i)
      y = p[y];

    vector<int> path;
    for (int cur = y;; cur = p[cur]) {
      path.push_back(cur);
      if (cur == y && path.size() > 1)
        break;
    }
    reverse(path.begin(), path.end());

    cout << "YES\n";
    for (int u : path)
      cout << u + 1 << ' ';
    return true;
  }
}
set<Edge> ed;
void dfs(ll v, vector<vector<pair<ll, ll>>> &grp, vector<bool> &vis) {
  vis[v] = 1;
  for (auto [u, w] : grp[v]) {
    if (!vis[u]) {
      ed.insert({v, u, w});
      dfs(u, grp, vis);
    }
  }
}
void solve() {
  ll n, m;
  cin >> n >> m;
  vector<vector<pair<ll, ll>>> grp(n);
  vector<bool> vis(n, 0);
  vector<Edge> edges;
  for (int i = 0; i < m; i++) {
    ll u, v, w;
    cin >> u >> v >> w;
    u--;
    v--;
    grp[u].push_back({v, w});
    // grp[v].push_back({u, w});
  }
  for (int i = 0; i < n; i++) {
    if (!vis[i]) {
      dfs(i, grp, vis);
      vector<Edge> edges(ed.begin(), ed.end());
      if (neg_cyc(i, edges.size(), edges))
        return;
      ed.clear();
      vis.assign(n, 0);
    }
  }
  cout << "NO\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  // freopen("cycle.in", "r", stdin);
  // freopen("cycle.out", "w", stdout);
  solve();
#ifdef ONPC
  cerr << endl
       << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif
}
