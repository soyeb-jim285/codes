#include <bits/stdc++.h>
using namespace std;

#define sz(a) ((int)((a).size()))

typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
ll bfs(ll ver, vector<vector<ll>> &grp, vector<bool> &vis, vector<bool> &inf) {
  queue<ll> q;
  q.push(ver);
  vis[ver] = true;
  inf[ver] = true;
  ll a = 1, b = 0;
  while (!q.empty()) {
    ll ver = q.front();
    q.pop();
    for (auto i : grp[ver]) {
      if (!vis[i]) {
        q.push(i);
        /* cout << i << "\n"; */
        vis[i] = true;
        inf[i] = !inf[ver];
        if (inf[i])
          a++;
        else
          b++;
      }
    }
  }
  /* for (auto ic : inf) { */
  /*   cout << ic << " "; */
  /* } */
  /* cout << "\n"; */
  /* cout << a << " " << b << "\n"; */
  return max(a, b);
}
void solve() {
  ll n;
  cin >> n;
  vector<vector<ll>> grp(2e4 + 1);
  vector<bool> vis(2e4 + 1), inf(2e4 + 1);
  for (int i = 0; i < n; i++) {
    ll u, v;
    cin >> u >> v;
    grp[u].push_back(v);
    grp[v].push_back(u);
  }
  ll ans = 0;
  for (int i = 1; i <= 2e4; i++) {
    if (!vis[i] && !grp[i].empty()) {
      ans += bfs(i, grp, vis, inf);
    }
  }
  cout << ans << '\n';
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t, tt = 1;
  cin >> t;
  while (t--) {
    cout << "Case " << tt++ << ": ";
    solve();
  }
#ifdef ONPC
  cerr << endl
       << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif
}
