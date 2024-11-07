#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
ll const N = 1e5 + 1;
vector<vector<ll>> grp(N);
vector<bool> vis(N);
vector<int> col(N, -1);
bool imp = 0;
void bfs(ll i) {
  vis[i] = true;
  col[i] = 1;
  queue<ll> q;
  q.push(i);
  while (!q.empty()) {
    ll x = q.front();
    q.pop();
    for (auto y : grp[x]) {
      if (col[x] == 1) {
        if (col[y] == 1) {
          imp = 1;
          return;
        }
        col[y] = 2;
      } else {
        if (col[y] == 2) {
          imp = 1;
          return;
        }
        col[y] = 1;
      }
      if (!vis[y]) {
        vis[y] = true;
        q.push(y);
      }
    }
  }
}
void solve() {
  ll n, m;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    ll u, v;
    cin >> u >> v;
    grp[u].push_back(v);
    grp[v].push_back(u);
  }
  for (int i = 0; i < n; i++) {
    if (!vis[i + 1])
      bfs(i + 1);
    if (imp) {
      cout << "IMPOSSIBLE\n";
      return;
    }
  }
  for (int i = 0; i < n; i++) {
    cout << col[i + 1] << " ";
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
