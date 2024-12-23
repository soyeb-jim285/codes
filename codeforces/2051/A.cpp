#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

void solve() {
  ll n;
  cin >> n;
  vector<ll> a(n), b(n);
  for (ll i = 0; i < n; i++) {
    cin >> a[i];
  }
  cin >> b[0];
  b[0] = 0;
  for (int i = 0; i < n - 1; i++) {
    cin >> b[i];
  }
  ll ans = 0;
  for (int i = 0; i < n; i++) {
    ll sum = a[i] - b[i];
    if (sum > 0)
      ans += sum;
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
