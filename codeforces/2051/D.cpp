#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

void solve() {
  ll n, x, y, sum = 0;
  cin >> n >> x >> y;
  vector<ll> a(n);
  for (ll i = 0; i < n; i++) {
    cin >> a[i];
    sum += a[i];
  }
  sort(all(a));
  ll ans = 0;
  for (int i = 0; i < n; i++) {
    ll sm = sum - a[i] - y;
    ll lg = sum - a[i] - x;
    ll ic = lower_bound(a.begin() + i + 1, a.end(), sm) - a.begin();
    ll ic2 = upper_bound(a.begin() + i + 1, a.end(), lg) - a.begin();
    ll d = ic2 - ic;
    // cout << sum << " " << sm << " " << lg << " " << i << " " << a[i] << " "
    //      << ic2 << " " << ic << " " << d << "\n";
    if (d)
      ans += d;
  }
  cout << ans << endl;
}
int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
#ifdef ONPC
  cerr << endl
       << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif
}
