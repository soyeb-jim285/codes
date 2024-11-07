#include <bits/stdc++.h>
using namespace std;

#define sz(a) ((int)((a).size()))

typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
ll const mod = 1e9 + 7;
ll fn(ll m, vector<ll> &dp) {
  if (dp[m] != -1)
    return dp[m];
  if (m == 0)
    return dp[m] = 1;
  if (m == 1)
    return dp[m] = 1;
  ll ans = (fn(m - 1, dp) + 2 * (m - 1) * fn(m - 2, dp)) % mod;
  return dp[m] = ans;
}
void solve() {
  ll n, k;
  cin >> n >> k;
  ll m = n;
  for (int i = 0; i < k; i++) {
    ll a, b;
    cin >> a >> b;
    if (a == b) {
      m--;
    } else {
      m -= 2;
    }
  }
  vector<ll> dp(m + 1, -1);
  cout << fn(m, dp) << '\n';
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
