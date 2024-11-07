#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
ll const mod = 1e9 + 7;
ll fn(ll num, vector<ll> &dp) {
  if (num == 0)
    return 1;
  if (num < 0)
    return 0;
  if (dp[num] != -1)
    return dp[num];
  ll ans = 0;
  for (ll i = 1; i <= 6; i++) {
    ans += fn(num - i, dp);
    ans %= mod;
  }
  return dp[num] = ans;
}
void solve() {
  ll n;
  cin >> n;
  vector<ll> dp(n + 1, 0);
  dp[0] = 1;
  for (ll i = 1; i <= n; i++) {
    for (ll j = 1; j <= 6; j++) {
      if (i - j >= 0) {
        dp[i] += dp[i - j];
        dp[i] %= mod;
      }
    }
  }
  cout << dp[n] << endl;
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
