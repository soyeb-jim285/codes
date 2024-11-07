#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
void solve() {
  ll x, time;
  cin >> x >> time;
  ll n, rem = time;
  cin >> n;
  ld ans, d = 0;
  for (int i = 0; i < n; i++) {
    ll l, r;
    cin >> l >> r;
    ld f;
    cin >> f;
    d += (r - l) * f;
    rem -= (r - l);
  }
  // cout << setprecision(10) << d << ' ' << rem << endl;
  ans = x / (d + rem);
  cout << fixed << setprecision(10) << ans << endl;
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
