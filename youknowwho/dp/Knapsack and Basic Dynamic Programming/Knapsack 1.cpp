#include <bits/stdc++.h>
#include <utility>
#include <vector>
using namespace std;
typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
void solve() {
  ll n, w;
  cin >> n >> w;
  vector<pair<ll, ll>> vc(n);
  for (int i = 0; i < n; i++) {
    cin >> vc[i].first >> vc[i].second;
  }
  vector<vector<ll>> dp(n + 1, vector<ll>(w + 1));
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= w; j++) {
      if (i == 0 || j == 0)
        dp[i][j] = 0;
      else if (vc[i - 1].first <= j) {
        dp[i][j] = max(dp[i - 1][j - vc[i - 1].first] + vc[i - 1].second,
                       dp[i - 1][j]);
      } else
        dp[i][j] = dp[i - 1][j];
      // cout << dp[i][j] << " (" << i << ", " << j << ")\n";
    }
  }
  cout << dp[n][w] << "\n";
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
