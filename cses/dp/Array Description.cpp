#include <bits/stdc++.h>
#include <vector>
using namespace std;
typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
ll fn(ll indx, ll prev, vector<vector<ll>> &dp, vector<ll> &a, ll n, ll m) {
  if (indx == n)
    return 1;
  if (dp[indx][prev] != -1)
    return dp[indx][prev];
  if (prev == 0 && indx == 0 && a[indx] == 0) {
    ll ans = 0;
    for (int i = 1; i <= m; i++) {
      ans += fn(indx + 1, i, dp, a, n, m);
      ans %= 1000000007;
    }
    return dp[indx][prev] = ans;
  }
  if (a[indx] != 0) {
    if (abs(a[indx] - prev) > 1 && prev != 0)
      return dp[indx][prev] = 0;
    return dp[indx][prev] = fn(indx + 1, a[indx], dp, a, n, m);
  } else {
    ll ans = 0;
    for (int i = max(1LL, prev - 1); i <= min(prev + 1, m); i++) {
      ans = (ans + fn(indx + 1, i, dp, a, n, m)) % 1000000007;
    }
    return dp[indx][prev] = ans;
  }
}
void solve() {
  ll n, m;
  cin >> n >> m;
  vector<ll> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector<vector<ll>> dp(n, vector<ll>(m + 1, -1));
  cout << fn(0, 0, dp, a, n, m) << endl;
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
