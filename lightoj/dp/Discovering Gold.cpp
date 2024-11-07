#include <bits/stdc++.h>
using namespace std;

#define sz(a) ((int)((a).size()))

typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
void solve() {
  ll n;
  cin >> n;
  vector<ll> a(n);
  for (ll &x : a)
    cin >> x;
  vector<ld> dp(n);
  dp[0] = a[0];
  for (int i = 1; i < n; i++) {
    dp[i] = a[i];
    for (int j = 1; j <= 6; j++) {
      if (i >= 6)
        dp[i] += dp[i - j] / 6;
      else {
        if (i - j >= 0)
          dp[i] += dp[i - j] / i;
      }
    }
  }
  cout << fixed << setprecision(10) << dp[n - 1] << endl;
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
