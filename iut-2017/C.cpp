#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
void solve() {
  ll e;
  cin >> e;
  168 vector<vector<pair<ll, ll>>> grp(e + 1);
  for (int i = 0; i < e; i++) {
    ll u, v, w;
    cin >> u >> v >> w;
    grp[u].push_back({v, w});
    grp[v].push_back({u, w});
  }
  ll q;
  cin >> q;
  while (q--) {
    ll a, t1, b, t2;
    cin >> a >> t1 >> b >> t2;
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
