#include <bits/stdc++.h>
using namespace std;

#define sz(a) ((int)((a).size()))

typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
void dfs() void solve() {
  ll n, m;
  cin >> n >> m;
  vector<vector<pair<ll, ll>>> g(n + 1);
  for (int i = 0; i < m; i++) {
    ll u, v, w;
    cin >> u >> v >> w;
    g[u].push_back({v, w});
    g[v].push_back({u, w});
  }
  vector<ll> s(n + 1), time(n + 1);
  vcetor<bool> vis(n + 1);
  for (int i = 0; i < n; i++) {
    cin >> s[i];
  }
}
int main() {
  ios::sync_with_stdio(false);
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
