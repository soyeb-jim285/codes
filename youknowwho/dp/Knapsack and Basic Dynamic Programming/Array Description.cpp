#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
const ll mod = 1e9 + 7;
ll fn(ll ind, ll prev, vector<ll> &vc, vector<vector<ll>> &dp, ll m) {
  if (ind == vc.size())
    return 1;
  if (dp[ind][prev] != -1)
    return dp[ind][prev];
  ll ans = 0;
  if (prev == 0 && ind == 0 && vc[ind] == 0) {
    for (int i = 1; i <= m; i++) {
      ans = (ans + fn(ind + 1, i, vc, dp, m)) % mod;
    }
    return dp[ind][prev] = ans;
  }
  if (vc[ind] == 0) {
    for (int i = max(1LL, prev - 1); i <= min(m, prev + 1); i++) {
      ans = (ans + fn(ind + 1, i, vc, dp, m)) % mod;
    }
  } else {
    if (abs(vc[ind] - prev) > 1 && prev != 0) {
      return dp[ind][prev] = 0;
    } else {
      ans = (ans + fn(ind + 1, vc[ind], vc, dp, m)) % mod;
    }
  }
  return dp[ind][prev] = ans;
}
void solve() {
  int n, m;
  cin >> n >> m;
  vector<ll> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector<vector<ll>> dp(n, vector<ll>(m + 1, -1));
  cout << fn(0, 0, a, dp, m) << endl;
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
