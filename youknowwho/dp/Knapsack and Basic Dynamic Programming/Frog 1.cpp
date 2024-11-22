#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
void solve() {
  ll n, k;
  cin >> n >> k;
  vector<ll> vc(n);
  for (int i = 0; i < n; i++) {
    cin >> vc[i];
  }
  vector<ll> dp(n, 1e18);
  dp[0] = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 1; j <= k; j++) {
      if (i + j < n) {
        dp[i + j] = min(dp[i + j], dp[i] + abs(vc[i] - vc[i + j]));
      }
    }
  }
  cout << dp[n - 1] << endl;
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
