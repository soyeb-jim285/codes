#include <bits/stdc++.h>
#include <iomanip>
using namespace std;
typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
vector<bool> vis(1e6 + 10);
vector<ll> val(1e6 + 10);
ll sum = 0, num = 0;
void dfs(ll ver, ll par, vector<vector<ll>> &grp) {
  vis[ver] = true;
  if (grp[ver].size() == 1 && ver != 1) {
    num += 1;
    sum += val[ver];
  }
  for (auto child : grp[ver]) {
    if (vis[child])
      continue;
    val[child] = val[ver] + 1;
    dfs(child, ver, grp);
  }
}
void solve() {
  ll n;
  cin >> n;
  vector<vector<ll>> grp(n + 1);
  for (int i = 0; i < n - 1; i++) {
    ll x, y;
    cin >> x >> y;
    grp[x].push_back(y);
    grp[y].push_back(x);
  }
  dfs(1, 0, grp);
  ld ans = sum;
  ans /= num;
  cout << ans << "\n";
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(16);
  solve();
#ifdef ONPC
  cerr << endl
       << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif
}
