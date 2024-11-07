#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
ll const INF = 1e18;
void dijkstra(ll s, vector<vector<pair<ll, ll>>> &grp,
              vector<pair<ll, ll>> &dist) {
  priority_queue<pair<ll, pair<ll, ll>>, vector<pair<ll, pair<ll, ll>>>,
                 greater<pair<ll, pair<ll, ll>>>>
      q;
  q.push({0, {s, 0}});
  dist[s] = {0, 0};
  while (q.size()) {
    auto [d, u] = q.top();
    cout << d << " " << u.first << " " << u.second << "--*--\n";
    q.pop();
    for (auto [v, w] : grp[u.first]) {
      // cout << v << " " << w << " " << u.first << " " << u.second << "--\n";
      if (u.second == 0) {
        if (dist[v].first > dist[u.first].first + w / 2) {
          dist[v].first = dist[u.first].first + w / 2;
          cout << dist[v].first << " " << v << " " << 1 << "----\n";
          q.push({dist[v].first, {v, 1}});
        }
        if (dist[v].second > dist[u.first].first + w) {
          dist[v].second = dist[u.first].first + w;
          cout << dist[v].second << " " << v << " " << 0 << "----\n";
          q.push({dist[v].second, {v, 0}});
        }
      } else {
        if (dist[u.first].second + w < dist[v].second) {
          dist[v].second = dist[u.first].second + w;
          cout << dist[v].second << " " << v << " " << 1 << "----\n";
          q.push({dist[v].second, {v, 1}});
        }
      }
    }
  }
}
void solve() {
  ll n, m;
  cin >> n >> m;
  vector<vector<pair<ll, ll>>> grp(n + 1);
  vector<pair<ll, ll>> dist(n + 1, {INF, INF});
  for (int i = 0; i < m; i++) {
    ll u, v, w;
    cin >> u >> v >> w;
    grp[u].push_back({v, w});
  }
  dijkstra(1, grp, dist);
  cout << dist[n].first << " " << dist[n].second << endl;
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
