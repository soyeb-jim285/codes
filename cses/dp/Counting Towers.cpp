#include <bits/stdc++.h>
using namespace std;

#define sz(a) ((int)((a).size()))

typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
ll const mod = 1e9 + 7, N = 1e6 + 1;
vector<vector<ll>> dp(N, vector<ll>(2, -1));
void fn() {
  dp[1][0] = dp[1][1] = 1;
  for (int i = 2; i < N; i++) {
    dp[i][0] = (dp[i - 1][0] * 4 + dp[i - 1][1]) % mod;
    dp[i][1] = (dp[i - 1][0] + dp[i - 1][1] * 2) % mod;
  }
}
void solve() {
  ll n;
  cin >> n;
  cout << (dp[n][0] + dp[n][1]) % mod << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  fn();
  int t;
  cin >> t;
  while (t--)
    solve();
#ifdef ONPC
  cerr << endl
       << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif
}
