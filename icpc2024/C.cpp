#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
void solve() {
  ll n, s;
  cin >> n >> s;
  ll ans = -1e18;
  for (int i = 0; i < n; i++) {
    ll f, t;
    cin >> f >> t;
    if (t <= s) {
      ans = max(ans, f);
    } else {
      ans = max(ans, f - (t - s));
    }
  }
  cout << ans << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ll t, tt = 1;
  cin >> t;
  while (t--) {
    cout << "Case #" << tt++ << ": ";
    solve();
  }
#ifdef ONPC
  cerr << endl
       << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif
}
