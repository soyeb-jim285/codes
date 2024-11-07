#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
vector<ll> dp(1e6 + 1, -1);
ll fn(ll sum, vector<ll> &coins) {
  if (dp[sum] != -1)
    return dp[sum];
  if (sum == 0)
    return 0;
  ll ans = 1e9;
  for (ll x : coins) {
    if (sum - x >= 0) {
      ans = min(ans, 1 + fn(sum - x, coins));
    }
  }
  return dp[sum] = ans;
}
void solve() {
  ll n, sum;
  cin >> n >> sum;
  vector<ll> coins(n);
  for (ll &x : coins)
    cin >> x;
  if (fn(sum, coins) == 1e9)
    cout << "-1" << endl;
  else
    cout << fn(sum, coins) << endl;
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
