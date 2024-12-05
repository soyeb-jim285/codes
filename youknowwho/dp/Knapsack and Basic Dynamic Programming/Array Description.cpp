#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
const ll mod = 1e9 + 7;

void solve() {
  int n, m;
  cin >> n >> m;
  vector<ll> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector<vector<ll>> dp(n, vector<ll>(m + 1, 0));
  if (a[0] == 0) {
    for (int j = 1; j <= m; j++) {
      dp[0][j] = 1;
    }
  } else {
    dp[0][a[0]] = 1;
  }
  for (int i = 1; i < n; i++) {
    if (a[i] == 0) {
      for (int j = 1; j <= m; j++) {
        dp[i][j] = dp[i - 1][j];
        if (j > 1)
          dp[i][j] = (dp[i][j] + dp[i - 1][j - 1]) % mod;
        if (j < m)
          dp[i][j] = (dp[i][j] + dp[i - 1][j + 1]) % mod;
      }
    } else {
      for (int j = 1; j <= m; j++) {
        dp[i][j] = 0;
      }
      if (abs(a[i] - a[i - 1]) <= 1 || a[i - 1] == 0) {
        dp[i][a[i]] = dp[i - 1][a[i]];
        if (a[i] > 1)
          dp[i][a[i]] = (dp[i][a[i]] + dp[i - 1][a[i] - 1]) % mod;
        if (a[i] < m)
          dp[i][a[i]] = (dp[i][a[i]] + dp[i - 1][a[i] + 1]) % mod;
      }
    }
  }
  ll result = 0;
  if (a[n - 1] == 0) {
    for (int j = 1; j <= m; j++) {
      result = (result + dp[n - 1][j]) % mod;
    }
  } else {
    result = dp[n - 1][a[n - 1]];
  }
  cout << result << endl;
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
