#include <bits/stdc++.h>
using namespace std;

#define sz(a) ((int)((a).size()))

typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
ll fn(int indx, int m, vector<ll> &a, vector<vector<ll>> dp) {
  if (indx == a.size()) {
    return 0;
  }
  if (dp[indx][m] != -1) {
    return dp[indx][m];
  }
  ll ans = 0;
  if (m >= a[indx]) {
    ans = max(ans, 1 + fn(indx + 1, m - a[indx], a, dp));
  }
  ans = max(ans, fn(indx + 1, m, a, dp));
  return dp[indx][m] = ans;
}
void solve() {
  ll n, m, ans = 0;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    m -= sz(s);
    if (m >= 0)
      ans++;
  }
  cout << ans << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--)
    solve();
#ifdef ONPC
  cerr << endl
       << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif
}
