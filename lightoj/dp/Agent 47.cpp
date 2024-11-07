#include <bits/stdc++.h>
using namespace std;

#define sz(a) ((int)((a).size()))

typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
bool check(ll mask, int i) { return (mask >> i) & 1; }
ll set_bit(ll mask, int i) { return mask = mask | (1 << i); }
void reset_bit(ll &mask, int i) { mask &= ~(1 << i); }
ll bitmask(ll i, ll mask, vector<vector<ll>> &dp, vector<vector<ll>> &a) {
  ll n = sz(a);
  if (mask == (1 << n) - 1)
    return 0;
  if (dp[i][mask] != -1)
    return dp[i][mask];
  ll ans = -1;
  for (int j = 0; j < n; j++) {
    if (check(mask, j))
      continue;
    ans = max(ans, a[i][j] + bitmask(i + 1, set_bit(mask, j), dp, a));
  }
  return dp[i][mask] = ans;
}
void solve() {
  ll n;
  cin >> n;
  vector<vector<ll>> a(n, vector<ll>(n)), dp(n, vector<ll>(1 << n, -1));
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      cin >> a[i][j];
  cout << bitmask(0, 0, dp, a) << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t, tt = 1;
  cin >> t;
  while (t--) {
    cout << "Case " << tt++ << ": ";
    solve();
  }
#ifdef ONPC
  cerr << endl
       << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif
}
