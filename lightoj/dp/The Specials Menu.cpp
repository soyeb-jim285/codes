#include <bits/stdc++.h>
using namespace std;

#define sz(a) ((int)((a).size()))

typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
void solve() {
  string s;
  cin >> s;
  vector<vector<ll>> dp(sz(s), vector<ll>(sz(s), 0));
  for (int i = sz(s) - 1; i >= 0; i--) {
    for (int j = i; j < sz(s); j++) {
      if (i == j) {
        dp[i][j] = 1;
        continue;
      }
      if (s[i] == s[j])
        dp[i][j] = 1 + dp[i + 1][j] + dp[i][j - 1];
      else {
        dp[i][j] = dp[i + 1][j] + dp[i][j - 1] - dp[i + 1][j - 1];
      }
    }
  }
  // for (int i = 0; i < sz(s); i++) {
  //   for (int j = 0; j < sz(s); j++) {
  //     cout << dp[i][j] << " ";
  //   }
  //   cout << endl;
  // }
  cout << dp[0][sz(s) - 1] << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
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
