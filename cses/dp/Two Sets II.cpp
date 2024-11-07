#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
ll const mod = 1e9 + 7;
vector<vector<int>> dp(510, vector<int>(501 * 250, -1));
ll binpowmod(ll a, ll b, ll m) {
  ll res = 1;
  while (b > 0) {
    if (b & 1) {
      res *= a;
      res = res % m;
    }
    a *= a;
    a = a % m;
    b >>= 1;
  }
  return res;
}
ll fn(ll i, ll sum, ll n, vector<vector<int>> &dp) {
  // cout << i << ' ' << sum << endl;
  if (dp[i][sum] != -1) {
    return dp[i][sum];
  }
  ll total = n * (n + 1) / 2;
  if (2 * sum == total) {
    return 1;
  }
  if (2 * sum > total) {
    return 0;
  }
  if (i > n) {
    return 0;
  }
  ll ans = fn(i + 1, sum, n, dp) % mod;
  ans = (ans + fn(i + 1, sum + i, n, dp)) % mod;
  return dp[i][sum] = ans;
}
void solve() {
  ll n;
  cin >> n;
  cout << (fn(1, 0, n, dp) * binpowmod(2, mod - 2, mod)) % mod << endl;
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
