#include <bits/stdc++.h>
using namespace std;

#define sz(a) ((int)((a).size()))

typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
ll const INF = 1e18;
bool check(ll mask, ll ind) { return (mask & (1 << ind)); }
ll set_bit(ll mask, ll ind) { return mask = mask | (1 << ind); }
ll bitmask(ll ind, ll mask, vector<vector<ll>> &dp, vector<pair<ll, ll>> &vc,
           vector<vector<ll>> &cols) {
  ll n = sz(vc);
  if (ind == n || mask == (1 << n) - 1)
    return 0;
  if (dp[ind][mask] != -1)
    return dp[ind][mask];
  if (ind == n - 1 || __builtin_popcount(mask) == n - 1 ||
      __builtin_popcount(mask) == n - 2) {
    return 1;
  }
  if (check(mask, ind))
    return dp[ind][mask] = bitmask(ind + 1, mask, dp, vc, cols);
  ll mk = mask;
  mk = set_bit(mk, ind);
  ll ans = INF;
  for (int i = ind + 1; i < n; i++) {
    if (check(mask, i))
      continue;
    ans = min(ans, 1 + bitmask(ind + 1, mask | cols[ind][i], dp, vc, cols));
  }
  return dp[ind][mask] = ans;
}
void solve() {
  ll n;
  cin >> n;
  vector<pair<ll, ll>> vc(n);
  for (int i = 0; i < n; i++) {
    cin >> vc[i].first >> vc[i].second;
  }
  vector<vector<ll>> dp(n, vector<ll>(1 << n, -1));
  vector<vector<ll>> cols(n, vector<ll>(n, 0));
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      ll tmp = 0;
      tmp = set_bit(tmp, i);
      tmp = set_bit(tmp, j);
      for (int k = 0; k < n; k++) {
        ll x1 = vc[i].first, y1 = vc[i].second;
        ll x2 = vc[j].first, y2 = vc[j].second;
        ll x3 = vc[k].first, y3 = vc[k].second;
        if ((x1 - x2) * (y3 - y2) == (x3 - x2) * (y1 - y2))
          tmp = set_bit(tmp, k);
      }
      cols[i][j] = tmp;
    }
  }
  cout << bitmask(0, 0, dp, vc, cols) << endl;
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
