#include <bits/stdc++.h>
using namespace std;

#define sz(a) ((int)((a).size()))

typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
ll fn(ll k, ll indx, ll w, vector<pair<ll, ll>> &a, vector<vector<ll>> &dp) {
  // cout << indx << "----\n";
  if (k == 0 || indx == a.size())
    return 0;
  if (dp[indx][k] != -1)
    return dp[indx][k];
  ll ans = 0, hight = a[indx].first;
  for (int i = indx; i < a.size(); i++) {
    if (a[i].first > hight + w)
      break;
    ans++;
  }
  // cout << indx << " " << k << " " << ans << " " << hight << " " << w << '\n';
  auto it =
      upper_bound(a.begin(), a.end(), make_pair(hight + w + 1, (ll)-1e10)) -
      a.begin();
  // ans = it - indx;
  // cout << indx << " " << k << " " << it << '\n';
  ll mx = 0;
  for (int i = it; i < a.size(); i++) {
    // cout << "i: " << i << '\n';
    mx = max(mx, fn(k - 1, i, w, a, dp));
  }
  return dp[indx][k] = ans + mx;
}
void solve() {
  ll n, w, k;
  cin >> n >> w >> k;
  vector<pair<ll, ll>> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i].second >> a[i].first;
  }
  sort(a.begin(), a.end());
  // for (auto ic : a)
  //   cout << ic.first << " " << ic.second << '\n';
  vector<vector<ll>> dp(n, vector<ll>(k + 1, -1));
  ll mx = -1;
  for (int i = 0; i < n; i++) {
    // cout << "i: " << i << "\n" << fn(k, i, w, a, dp) << '\n';
    mx = max(mx, fn(k, i, w, a, dp));
  }
  cout << mx << '\n';
  // cout << fn(k, 0, w, a, dp) << '\n';
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
