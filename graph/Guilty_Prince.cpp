#include <bits/stdc++.h>
using namespace std;

#define sz(a) ((int)((a).size()))

typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
void dfs(ll i, ll j, vector<vector<char>> &grp, vector<vector<bool>> &vis) {
  if (i < 0 || j < 0 || i >= sz(grp) || j >= sz(grp[0]) || vis[i][j] ||
      grp[i][j] == '#')
    return;
  vis[i][j] = true;
  dfs(i + 1, j, grp, vis);
  dfs(i - 1, j, grp, vis);
  dfs(i, j + 1, grp, vis);
  dfs(i, j - 1, grp, vis);
}
void solve() {
  ll n, m;
  cin >> m >> n;
  vector<vector<char>> grp(n, vector<char>(m));
  vector<vector<bool>> vis(n, vector<bool>(m));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> grp[i][j];
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (grp[i][j] == '@') {
        dfs(i, j, grp, vis);
      }
    }
  }
  ll ans = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      ans += vis[i][j];
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
