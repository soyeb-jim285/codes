#include <bits/stdc++.h>
using namespace std;

#define sz(a) ((int)((a).size()))

typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
ll const mod = 1e9 + 7;
void solve() {
  int n;
  cin >> n;
  vector<int> vc(n);
  for (int &x : vc)
    cin >> x;
  vector<vector<ll>> dp(n + 1, vector<ll>(n, 0));
  dp[0][0] = 1;
  for (int i = 0; i < n; i++) {
    for (int szz = 0; szz < n; szz++) {
      for (int j = 0; j < n; j++) {
        int k = (vc[i] + vc[j]) % n;
      }
      for (int j = 0; j < szz + 1; j++) {
        int nrem = (j + vc[i]) % (szz + 1);
        dp[szz + 1][nrem] = (dp[szz + 1][nrem] + dp[szz][j]) % mod;
      }
    }
  }
  ll ans = 0;
  for (int i = 0; i <= n; i++) {
    cout << i << " " << dp[i][0] << '\n';
    ans = (ans + dp[i][0]) % mod;
  }
  cout << ans << "\n";
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
