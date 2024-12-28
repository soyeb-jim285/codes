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
  vector<ll> a(n);
  for (ll &x : a)
    cin >> x;
  for (int i = 0; i < n - 1; i++) {
    if (2 * a[i] > a[i + 1] && 2 * a[i + 1] > a[i]) {
      cout << "YES" << endl;
      return;
    }
  }
  reverse(all(a));
  for (int i = 0; i < n - 1; i++) {
    if (2 * a[i] > a[i + 1] && 2 * a[i + 1] > a[i]) {
      cout << "YES" << endl;
      return;
    }
  }
  cout << "NO" << endl;
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
