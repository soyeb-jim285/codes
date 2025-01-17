#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
const ll mod = 1e9 + 7;
ll fn(ll val, vector<ll> &vc, vector<ll> &dp) {
  if (val == 0)
    return 1;
  if (val < 0)
    return 0;
  if (dp[val] != -1)
    return dp[val];
  ll ans = 0;
  for (int i = 0; i < vc.size(); i++) {
    ans = (ans + fn(val - vc[i], vc, dp)) % mod;
  }
  return dp[val] = ans;
}
void solve() {
  ll n, x;
  cin >> n >> x;
  vector<ll> vc(n);
  for (int i = 0; i < n; i++) {
    cin >> vc[i];
  }
  vector<ll> dp(x + 1, 0);
  dp[0] = 1;
  for (int i = 0; i <= x; i++) {
    for (int j = 0; j < n; j++) {
      if (i - vc[j] >= 0) {
        dp[i] = (dp[i] + dp[i - vc[j]]) % mod;
      }
    }
  }
  cout << dp[x] << endl;
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
