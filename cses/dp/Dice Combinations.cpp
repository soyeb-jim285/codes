#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
vector<ll> dice = {1, 2, 3, 4, 5, 6};
vector<ll> dp(1e6 + 1, -1);
ll const mod = 1e9 + 7;
ll fn(ll n) {
  if (dp[n] != -1)
    return dp[n];
  if (n == 0)
    return 1;
  ll ans = 0;
  for (ll i = 0; i < 6; i++) {
    if (n - dice[i] >= 0) {
      ans = (ans + fn(n - dice[i])) % mod;
    }
  }
  return dp[n] = ans;
}
void solve() {
  ll n;
  cin >> n;
  cout << fn(n) << endl;
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
