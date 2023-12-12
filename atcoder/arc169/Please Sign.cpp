#include <vector>
// #ifdef ONPC
// #define _GLIBCXX_DEBUG
// #endif
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
ll ans = 0;
ll const N = 250000 + 10;
vector<ll> hight(N);
void dfs(ll ind, vector<vector<ll>> &grp, vector<ll> &val) {
  ans += val[ind];
  // cout << ind << " " << val[ind] << " " << ans << "\n";
  for (auto child : grp[ind]) {
    dfs(child, grp, val);
    hight[ind] = max(hight[ind], hight[child] + 1);
  }
}
void solve() {
  ll n;
  cin >> n;
  vector<ll> val(n + 1), as(n);
  vector<vector<ll>> grp(n + 1);
  for (int i = 0; i < n; i++) {
    cin >> val[i + 1];
  }
  for (int i = 0; i < n - 1; i++) {
    ll x;
    cin >> x;
    grp[x].push_back(i + 2);
  }
  dfs(1, grp, val);
  // for (int i = 1; i < n; i++) {
  //   cout << i << ":\n";
  //   for (auto ic : grp[i])
  //     cout << ic << " ";
  //   cout << "\n";
  // }
  for (int i = 1; i <= n; i++) {
    as[hight[i]] += val[i];
  }
  // for (auto ic : as)
  //   std::cout << ic << " ";
  // cout << "\n";
  for (auto ic : as) {
    if (ic < 0) {
      cout << "-\n";
      return;
    } else if (ic > 0) {
      cout << "+\n";
      return;
    }
  }
  cout << "0\n";
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();
#ifdef ONPC
  cerr << endl
       << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif
}
