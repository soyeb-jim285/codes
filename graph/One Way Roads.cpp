#include <bits/stdc++.h>
using namespace std;

#define sz(a) ((int)((a).size()))

typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
ll dfs(ll ver, ll par, ll fst, vector<vector<pair<ll, ll>>> &grp) {
  ll a = 0;
  for (auto &i : grp[ver]) {
    if (i.first == par)
      continue;
    if (i.first != fst) {
      a += dfs(i.first, ver, fst, grp) + i.second;
    }
  }
  return a;
}
void solve() {
  ll n;
  cin >> n;
  vector<vector<pair<ll, ll>>> grp(n + 1);
  vector<bool> vis(n + 1);
  for (int i = 0; i < n; i++) {
    ll u, v, w;
    cin >> u >> v >> w;
    grp[u].push_back({v, 0});
    grp[v].push_back({u, w});
  }
  ll mn = 1e18;
  for (int i = 1; i <= n; i++) {
    mn = min(
        {mn, dfs(grp[i][0].first, i, grp[i][0].first, grp) + grp[i][0].second,
         dfs(grp[i][1].first, i, grp[i][1].first, grp) + grp[i][1].second});
  }
  cout << mn << "\n";
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t, t1 = 1;
  cin >> t;
  while (t--) {
    cout << "Case " << t1++ << ": ";
    solve();
  }
#ifdef ONPC
  cerr << endl
       << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif
}
