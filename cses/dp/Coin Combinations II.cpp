#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
vector<vector<ll>> dp(1e6 + 1, vector<ll>(101, -1));
ll const mod = 1e9 + 7;
ll fn(ll sum, ll coin, vector<ll> &coins) {
  if (dp[sum][coin] != -1)
    return dp[sum][coin];
  if (sum == 0)
    return 1;
  ll ans = 0;
  if (sum - coins[coin] >= 0)
    ans = (ans + fn(sum - coins[coin], coin, coins)) % mod;
  if (coin > 0)
    ans = (ans + fn(sum - coins[coin], coin - 1, coins)) % mod;
  return dp[sum][coin] = ans;
}
void solve() {
  ll n, sum;
  cin >> n >> sum;
  vector<ll> coins(n);
  for (ll &x : coins)
    cin >> x;
  ll ans = 0;
  for (int i = 0; i < n; i++) {
    memset(dp.data(), -1, sizeof dp);
    ans += fn(sum, i, coins);
    ans %= mod;
  }
  cout << ans % mod << endl;
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
