#include <bits/stdc++.h>
using namespace std;

#define sz(a) ((int)((a).size()))

typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
bool fn(ll mid, ll x, ll m) {
  ll d = x ^ mid;
  return d <= m;
}
void solve() {
  ll x, m;
  cin >> x >> m;
  ll ans = 0;
  for (int i = 1; i <= min(x, m); i++) {
    ll d = x ^ i;
    if (d % x == 0 || d % i == 0) {
      ans++;
    }
  }
  if (m <= x) {
    cout << ans << '\n';
    return;
  }
  ll l = 1, r = ceil(2.0 * m / x);
  while (l < r) {
    ll mid = (l + r) / 2;
    if (fn(mid * x, x, m)) {
      l = mid + 1;
    } else {
      r = mid;
    }
  }
  ll mx = 1;
  for (ll i = max(2LL, l - 5); i <= (l + 5); i++) {
    if (fn(i * x, x, m)) {
      mx = max(mx, i);
    }
  }
  // cout << ans << ' ' << mx << ' ' << "\n";
  if (fn((mx - 1) * x, x, m)) {
    ans += mx - 1;
  } else {
    ans += mx - 2;
  }
  cout << ans << '\n';
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
