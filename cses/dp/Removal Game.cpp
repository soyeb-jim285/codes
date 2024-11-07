#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
ll const N = 5000 + 1;
vector<vector<ll>> dp(N, vector<ll>(N, -1));
ll fn(ll i, ll j, vector<ll> &a, vector<vector<ll>> &dp) {
  if (dp[i][j] != -1) {
    return dp[i][j];
  }
  if (i > j) {
    return 0;
  }
  if (i == j)
    return dp[i][j] = a[i];
  if (j - 1 == i)
    return dp[i][j] = max(a[i], a[j]);
  ll ans = a[i] + min(fn(i + 2, j, a, dp), fn(i + 1, j - 1, a, dp));
  ans = max(ans, a[j] + min(fn(i + 1, j - 1, a, dp), fn(i, j - 2, a, dp)));
  return dp[i][j] = ans;
}
void solve() {
  ll n;
  cin >> n;
  vector<ll> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  cout << fn(0, n - 1, a, dp) << endl;
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
