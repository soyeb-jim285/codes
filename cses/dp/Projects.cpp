#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
ll const N = 2e5 + 1;
vector<ll> dp(N, -1);
ll fn(ll ind, vector<vector<ll>> &a) {
  if (ind == a.size())
    return 0;
  if (dp[ind] != -1)
    return dp[ind];
  ll ans = fn(ind + 1, a);
  vector<ll> b = {a[ind][1], (ll)1e9, (ll)1e9};
  auto ic = upper_bound(a.begin(), a.end(), b) - a.begin();
  // cout << a[ind][0] << " " << ic << endl;
  ans = max(ans, a[ind][2] + fn(ic, a));
  return dp[ind] = ans;
}
void solve() {
  ll n;
  cin >> n;
  vector<vector<ll>> a(n, vector<ll>(3));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 3; j++) {
      cin >> a[i][j];
    }
  }
  sort(a.begin(), a.end());
  cout << fn(0, a) << endl;
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
