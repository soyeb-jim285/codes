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
  ll nozero_segs = 0, zeros = 0, nozero = 0;
  for (ll x : a) {
    if (x == 0) {
      if (nozero) {
        nozero_segs++;
        nozero = 0;
      }
      zeros++;
    } else {
      nozero++;
      zeros = 0;
    }
  }
  if (nozero) {
    nozero_segs++;
  }
  if (nozero_segs == 0) {
    cout << 0 << endl;
    return;
  } else if (nozero_segs == 1) {
    cout << 1 << endl;
    return;
  } else if (nozero_segs == 2) {
    cout << 2 << endl;
    return;
  } else {
    cout << 2 << endl;
    return;
  }
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
