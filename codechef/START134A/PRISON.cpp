#include <bits/stdc++.h>
using namespace std;

#define sz(a) ((int)((a).size()))

typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
ll const INF = 1e9;
void dijkstra(vector<vector<char>> &a, vector<vector<ll>> &dist) {
  priority_queue<pair<ll, pair<ll, ll>>, vector<pair<ll, pair<ll, ll>>>,
                 greater<pair<ll, pair<ll, ll>>>>
      pq;
  ll n = a.size(), m = a[0].size();
  // for (int i = 0; i < n; i++) {
  //   if (a[i][0] == '0') {
  //     dist[i][0] = 0;
  //     pq.push({0, {i, 0}});
  //   } else {
  //     dist[i][0] = 1;
  //     // pq.push({1, {i, 0}});
  //   }
  //   if (a[i][m - 1] == '0') {
  //     dist[i][m - 1] = 0;
  //     pq.push({0, {i, m - 1}});
  //   } else {
  //     dist[i][m - 1] = 1;
  //     // pq.push({1, {i, m - 1}});
  //   }
  // }
  // for (int i = 0; i < m; i++) {
  //   if (a[0][i] == '0') {
  //     dist[0][i] = 0;
  //     pq.push({0, {0, i}});
  //   } else {
  //     dist[0][i] = 1;
  //     // pq.push({1, {0, i}});
  //   }
  //   if (a[n - 1][i] == '0') {
  //     dist[n - 1][i] = 0;
  //     pq.push({0, {n - 1, i}});
  //   } else {
  //     dist[n - 1][i] = 1;
  //     // pq.push({1, {n - 1, i}});
  //   }
  // }
  if (pq.size() == 0) {
    for (int i = 0; i < n; i++) {
      dist[i][0] = 0;
      pq.push({0, {i, 0}});
      dist[i][m - 1] = 0;
      pq.push({0, {i, m - 1}});
    }
    for (int i = 0; i < m; i++) {
      dist[0][i] = 0;
      pq.push({0, {0, i}});
      dist[n - 1][i] = 0;
      pq.push({0, {n - 1, i}});
    }
  }
  while (pq.size()) {
    auto [d, p] = pq.top();
    pq.pop();
    auto [x, y] = p;
    if (dist[x][y] != d)
      continue;
    int xx = x + 1, yy = y;
    int w = a[x][y] == '1';
    if (xx < n && yy < m && xx >= 0 && yy >= 0) {
      if (dist[xx][yy] > dist[x][y] + w) {
        dist[xx][yy] = dist[x][y] + w;
        pq.push({dist[xx][yy], {xx, yy}});
      }
    }
    xx = x - 1, yy = y;
    if (xx < n && yy < m && xx >= 0 && yy >= 0) {
      if (dist[xx][yy] > dist[x][y] + w) {
        dist[xx][yy] = dist[x][y] + w;
        pq.push({dist[xx][yy], {xx, yy}});
      }
    }
    xx = x, yy = y + 1;
    if (xx < n && yy < m && xx >= 0 && yy >= 0) {
      if (dist[xx][yy] > dist[x][y] + w) {
        dist[xx][yy] = dist[x][y] + w;
        pq.push({dist[xx][yy], {xx, yy}});
      }
    }
    xx = x;
    yy = y - 1;
    if (xx < n && yy < m && xx >= 0 && yy >= 0) {
      if (dist[xx][yy] > dist[x][y] + w) {
        dist[xx][yy] = dist[x][y] + w;
        pq.push({dist[xx][yy], {xx, yy}});
      }
    }
  }
}
void solve() {
  ll n, m;
  cin >> n >> m;
  vector<vector<char>> a(n, vector<char>(m));
  vector<vector<ll>> dist(n, vector<ll>(m, INF));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> a[i][j];
    }
  }
  dijkstra(a, dist);
  ll ans = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      // cout << dist[i][j] << " ";
      if (a[i][j] == '0' && dist[i][j] != INF)
        ans = max(ans, dist[i][j]);
    }
    // cout << "\n";
  }
  // cout << "\n";
  cout << ans << endl;
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
