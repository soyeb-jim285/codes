#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
vector<ll> dp(1e6 + 1, 1e18);
ll fn(ll val) {
  if (val == 0)
    return 0;
  if (dp[val] != 1e18)
    return dp[val];
  ll ans = 1e18, temp = val;
  while (temp) {
    ll dig = temp % 10;
    if (dig != 0)
      ans = min(ans, fn(val - dig) + 1);
    temp /= 10;
  }
  return dp[val] = ans;
}
void solve() {
  ll n;
  cin >> n;
  dp[0] = 0;
  for (int i = 0; i <= n; i++) {
    ll tmp = i;
    while (tmp) {
      ll dig = tmp % 10;
      if (dig != 0)
        dp[i] = min(dp[i], dp[i - dig] + 1);
      tmp /= 10;
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
