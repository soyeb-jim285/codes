#include <bits/stdc++.h>
using namespace std;

#define sz(a) ((int)((a).size()))

typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
ll fn(int ind, vector<pair<ll, ll>> &a, vector<ll> &dp) {
  if (ind == sz(a)) {
    return 0;
  }
  if (dp[ind] != -1) {
    return dp[ind];
  }
  ll res = fn(ind + 1, a, dp);
  ll l = 0, r = sz(a) - 1;
  while (l < r) {
    ll m = (l + r) / 2;
    if (a[m].first < a[ind].second) {
      l = m + 1;
    } else {
      r = m;
    }
  }
  res = max(res, a[ind].second - a[ind].first + fn(r, a, dp));
  return dp[ind] = res;
}
void solve() {
  ll m, x;
  cin >> m >> x;
  vector<pair<ll, ll>> a(m);
  for (int i = 0; i < m; i++) {
    cin >> a[i].first >> a[i].second;
  }
  vector<ll> dp(m + 1, -1);
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
