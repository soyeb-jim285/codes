#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
void solve() {
  ll n, x;
  cin >> n >> x;
  vector<ll> vc(n);
  for (int i = 0; i < n; i++) {
    cin >> vc[i];
  }
  vector<vector<ll>> dp(n + 1, vector<ll>(x + 1, 0));
  dp[0][0] = 1;
  for (int j = 0; j <= x; j++) {
    for (int i = 1; i <= n; i++) {
      if (vc[i - 1] <= j)
        dp[i][j] += dp[i][j - vc[i - 1]] + dp[i - 1][j];
      else
        dp[i][j] += dp[i - 1][j];
      cout << dp[i][j] << " ";
    }
    cout << "\n";
  }
  cout << dp[n][x] << "\n";
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
