#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
struct Edge {
  ll a, b, cost;
};
ll n, m, v;
vector<Edge> edges;
const ll INF = 1e18;
void solve() {
  cin >> n >> m;
  v = 0;
  for (int i = 0; i < m; ++i) {
    ll a, b, cost;
    cin >> a >> b >> cost;
    a--, b--;
    edges.push_back({a, b, -cost});
  }
  vector<ll> d(n, INF);
  d[v] = 0;
  vector<int> p(n, -1);
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
  if (x != -1) {
    for (int i = 0; i < n; ++i) {
      for (Edge e : edges)
        if (d[e.a] < INF) {
          d[e.b] = max(-INF, d[e.b]);
          if (d[e.b] > d[e.a] + e.cost) {
            d[e.b] = -INF;
          }
        }
    }
  }
  cout << (d[n - 1] == -INF ? -1 : -d[n - 1]) << endl;
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
