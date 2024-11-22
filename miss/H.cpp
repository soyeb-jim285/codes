#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
ll const MOD = 998244353;
void solve() {
  ll n, m, k;
  cin >> n >> m >> k;
  vector<vector<ll>> dp(n, vector<ll>(m));
  dp[0][0] = k;
  for (ll i = 0; i < n; i++) {
    for (ll j = 0; j < m; j++) {
      if (i == 0 && j == 0)
        continue;
      if (j == 0) {
        dp[i][j] = (dp[i - 1][j] * (k - 1)) % MOD;
      } else if (i == 0) {
        dp[i][j] = (dp[i][j - 1] * (k - 1)) % MOD;
      } else {
        dp[i][j] =
            ((dp[i][j - 1] * (k - 1) + dp[i][j - 1] * (k - 2) * (k - 2))) % MOD;
      }
    }
  }
  cout << dp[n - 1][m - 1] << endl;
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
