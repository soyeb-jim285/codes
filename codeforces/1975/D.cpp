#include <bits/stdc++.h>
using namespace std;

#define sz(a) ((int)((a).size()))

typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
ll const INF = 1e18;
void bfs(ll u, vector<vector<ll>> &tre, vector<ll> &dist) {
  queue<ll> q;
  q.push(u);
  dist[u] = 0;
  while (!q.empty()) {
    ll v = q.front();
    q.pop();
    for (ll to : tre[v]) {
      if (dist[to] == INF) {
        dist[to] = dist[v] + 1;
        q.push(to);
      }
    }
  }
}
void solve() {
  ll n;
  cin >> n;
  ll a, b;
  cin >> a >> b;
  vector<vector<ll>> tre(n + 1);
  for (int i = 0; i < n; i++) {
    ll u, v;
    cin >> u >> v;
    tre[u].push_back(v);
    tre[v].push_back(u);
  }
  vector<ll> dist(n + 1, INF);
  bfs(a, tre, dist);
  ll ds = dist[b];
  ll lng;
  for (int i = 1; i <= n; i++) {
    if (dist[i] > dist[lng]) {
      lng = i;
    }
  }
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
