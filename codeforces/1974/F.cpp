#include <bits/stdc++.h>
using namespace std;

#define sz(a) ((int)((a).size()))

typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
void solve() {
  ll a, b, n, m;
  cin >> a >> b >> n >> m;
  map<ll, ll> remapx, remapy;
  set<ll> sx, sy;
  vector<pair<ll, ll>> v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i].first >> v[i].second;
    sx.insert(v[i].first);
    sy.insert(v[i].second);
  }
  vector<ll> vx, vy;
  for (auto &x : sx) {
    vx.push_back(x);
  }
  for (auto &y : sy) {
    vy.push_back(y);
  }
  ll ct = 0;
  for (auto &x : sx) {
    remapx[x] = ct++;
  }
  ct = 0;
  for (auto &y : sy) {
    remapy[y] = ct++;
  }
  vector<vector<bool>> grid(sz(sx), vector<bool>(sz(sy), 0));
  for (int i = 0; i < n; i++) {
    grid[remapx[v[i].first]][remapy[v[i].second]] = 1;
  }
  vector<vector<ll>> prefix_sum(sz(sx) + 1, vector<ll>(sz(sy) + 1, 0));
  for (int i = 0; i < sz(sx); i++) {
    for (int j = 0; j < sz(sy); j++) {
      prefix_sum[i + 1][j + 1] = prefix_sum[i + 1][j] + prefix_sum[i][j + 1] -
                                 prefix_sum[i][j] + grid[i][j];
    }
  }
  ll l = 1, r = b, u = 1, d = a;
  bool pl = 0;
  vector<ll> ans(2);
  for (int i = 0; i < m; i++) {
    char ch;
    ll k;
    cin >> ch >> k;
    if (ch == 'U') {
      ll x1 = lower_bound(vx.begin(), vx.end(), u) - vx.begin();
      ll x2 = lower_bound(vx.begin(), vx.end(), u + k) - vx.begin();
      if (x2 == sz(vx))
        x2--;
      if (vx[x2] > u + k)
        x2--;
      u += k;
      ll y1 = lower_bound(vy.begin(), vy.end(), l) - vy.begin();
      ll y2 = lower_bound(vy.begin(), vy.end(), r) - vy.begin();
      if (vy[y2] > r)
        y2--;
      if (vy[y2] > r)
        y2--;
      x1++, x2++;
      y1++, y2++;
      ans[pl] = prefix_sum[x2][y2] - prefix_sum[x1 - 1][y2] -
                prefix_sum[x2][y1 - 1] + prefix_sum[x1 - 1][y1 - 1];
      pl ^= 1;
    } else if (ch == 'D') {
      ll x1 = lower_bound(vx.begin(), vx.end(), d - k) - vx.begin();
      ll x2 = lower_bound(vx.begin(), vx.end(), d) - vx.begin();
      if (x2 == sz(vx))
        x2--;
      if (vx[x2] > d)
        x2--;
      d -= k;
      ll y1 = lower_bound(vy.begin(), vy.end(), l) - vy.begin();
      ll y2 = lower_bound(vy.begin(), vy.end(), r) - vy.begin();
      if (y2 == sz(vy))
        y2--;
      if (vy[y2] > r)
        y2--;
      x1++, x2++;
      y1++, y2++;
      x1++;
      ans[pl] = prefix_sum[x2][y2] - prefix_sum[x1 - 1][y2] -
                prefix_sum[x2][y1 - 1] + prefix_sum[x1 - 1][y1 - 1];
      pl ^= 1;
    } else if (ch == 'L') {
      ll x1 = lower_bound(vx.begin(), vx.end(), u) - vx.begin();
      ll x2 = lower_bound(vx.begin(), vx.end(), d) - vx.begin();
      if (x2 == sz(vx))
        x2--;
      if (vx[x2] > d)
        x2--;
      ll y1 = lower_bound(vy.begin(), vy.end(), l) - vy.begin();
      ll y2 = lower_bound(vy.begin(), vy.end(), l + k) - vy.begin();
      if (y2 == sz(vy))
        y2--;
      if (vy[y2] > l + k)
        y2--;
      l += k;
      x1++, x2++;
      y1++, y2++;
      ans[pl] = prefix_sum[x2][y2] - prefix_sum[x1 - 1][y2] -
                prefix_sum[x2][y1 - 1] + prefix_sum[x1 - 1][y1 - 1];
      pl ^= 1;
    } else {
      ll x1 = lower_bound(vx.begin(), vx.end(), u) - vx.begin();
      ll x2 = lower_bound(vx.begin(), vx.end(), d) - vx.begin();
      if (x2 == sz(vx))
        x2--;
      if (vx[x2] > d)
        x2--;
      ll y1 = lower_bound(vy.begin(), vy.end(), r - k) - vy.begin();
      ll y2 = lower_bound(vy.begin(), vy.end(), r) - vy.begin();
      if (y2 == sz(vy))
        y2--;
      if (vy[y2] > r)
        y2--;
      r -= k;
      x1++, x2++;
      y1++, y2++;
      ans[pl] = prefix_sum[x2][y2] - prefix_sum[x1 - 1][y2] -
                prefix_sum[x2][y1 - 1] + prefix_sum[x1 - 1][y1 - 1];
      pl ^= 1;
    }
    cout << ans[0] << " " << ans[1] << '\n';
  }
  cout << ans[0] << " " << ans[1] << '\n';
}
int main() {
  // ios_base::sync_with_stdio(false);
  // cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--)
    solve();
#ifdef ONPC
  cerr << endl
       << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif
}
