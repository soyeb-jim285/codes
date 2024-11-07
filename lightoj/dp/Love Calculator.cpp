#include <bits/stdc++.h>
using namespace std;

#define sz(a) ((int)((a).size()))

typedef long long ll;
typedef long double ld;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
void solve() {
  string s1, s2;
  cin >> s1 >> s2;
  vector<vector<pair<ll, ll>>> dp(sz(s1) + 1,
                                  vector<pair<ll, ll>>(sz(s2) + 1, {0, 1}));
  for (int i = 0; i < sz(s1); i++) {
    dp[i + 1][0] = {dp[i][0].first + 1, 1};
  }
  for (int i = 0; i < sz(s2); i++) {
    dp[0][i + 1] = {dp[0][i].first + 1, 1};
  }
  for (int i = 1; i <= sz(s1); i++) {
    for (int j = 1; j <= sz(s2); j++) {
      if (s1[i - 1] == s2[j - 1]) {
        dp[i][j] = {dp[i - 1][j - 1].first + 1, dp[i - 1][j - 1].second};
      } else {
        dp[i][j].first = min(dp[i - 1][j].first, dp[i][j - 1].first) + 1;
        if (dp[i - 1][j].first == dp[i][j - 1].first) {
          dp[i][j].second = dp[i - 1][j].second + dp[i][j - 1].second;
        } else {
          if (dp[i - 1][j].first < dp[i][j - 1].first) {
            dp[i][j].second = dp[i - 1][j].second;
          } else {
            dp[i][j].second = dp[i][j - 1].second;
          }
        }
      }
    }
  }
  cout << dp[sz(s1)][sz(s2)].first << " " << dp[sz(s1)][sz(s2)].second << '\n';
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
