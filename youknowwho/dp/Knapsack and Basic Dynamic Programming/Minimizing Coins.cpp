#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
vector<ll> dp(1e6 + 1, 1e18);
ll fn(ll val, vector<ll> &vc) {
  if (dp[val] != 1e18)
    return dp[val];
  if (val == 0)
    return 0;
  ll ans = 1e18;
  for (int i = 0; i < vc.size(); i++) {
    if (val - vc[i] >= 0)
      ans = min(ans, fn(val - vc[i], vc) + 1);
  }
  return dp[val] = ans;
}
void solve() {
  ll n, x;
  cin >> n >> x;
  vector<ll> vc(n);
  for (int i = 0; i < n; i++) {
    cin >> vc[i];
  }
  dp[0] = 0;
  for (int i = 0; i <= x; i++) {
    for (int j = 0; j < n; j++) {
      if (i - vc[j] >= 0) {
        dp[i] = min(dp[i], dp[i - vc[j]] + 1);
      }
    }
  }
  cout << (dp[x] == 1e18 ? -1 : dp[x]) << endl;
  // cout << (fn(x, vc) == 1e18 ? -1 : fn(x, vc)) << endl;
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
