#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
void solve() {
  ll n, k;
  cin >> n >> k;
  vector<pair<ll, ll>> vc(n);
  for (int i = 0; i < n; i++) {
    cin >> vc[i].first;
    vc[i].second = i + 1;
  }
  sort(vc.begin(), vc.end());
  ll kk = log2(n);
  vector<vector<ll>> mns(kk + 1, vector<ll>(n + 1, 0));
  vector<vector<ll>> mxs(kk + 1, vector<ll>(n + 1, 0));
  for (int i = 0; i < n; i++) {
    mns[0][i] = vc[i].second;
    mxs[0][i] = vc[i].second;
  }
  for (int i = 1; i <= kk; i++) {
    for (int j = 0; j + (1 << i) <= n; j++) {
      mns[i][j] = min(mns[i - 1][j], mns[i - 1][j + (1 << (i - 1))]);
      mxs[i][j] = max(mxs[i - 1][j], mxs[i - 1][j + (1 << (i - 1))]);
    }
  }
  ll ans = 1e8;
  for (int i = 0; i <= n - k; i++) {
    ll kp = log2(k);
    ll mn = min(mns[kp][i], mns[kp][i + k - (1 << kp)]);
    ll mx = max(mxs[kp][i], mxs[kp][i + k - (1 << kp)]);
    ans = min(ans, mx - mn);
    // cout << mx << " " << mn << endl;
  }
  cout << ans << endl;
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
