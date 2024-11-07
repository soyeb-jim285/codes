#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
ll const N = 500 + 1;
vector<vector<ll>> dp(N, vector<ll>(N, -1));
ll fn(ll a, ll b) {
  if (dp[a][b] != -1)
    return dp[a][b];
  if (a == b)
    return dp[a][b] = 0;
  ll ans = 1e18;
  for (ll i = 1; i < a; i++) {
    ans = min(ans, fn(i, b) + fn(a - i, b) + 1);
  }
  for (ll i = 1; i < b; i++) {
    ans = min(ans, fn(a, i) + fn(a, b - i) + 1);
  }
  return dp[a][b] = ans;
}
void solve() {
  ll a, b;
  cin >> a >> b;
  cout << fn(a, b) << '\n';
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
