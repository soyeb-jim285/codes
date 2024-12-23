#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

void solve() {
  ll n, x, y;
  cin >> n >> x >> y;
  vector<ll> a(n, -1);
  x--;
  y--;
  a[x] = 0, a[y] = 1;
  if ((y - x) % 2 == 0) {
    a[(x + 1) % n] = 2;
  } else {
    a[(x + 1) % n] = 1;
  }
  ll ind = x - 1;
  if (ind < 0) {
    ind += n;
  }
  if ((x + n - y) % 2) {
    a[ind] = 1;
  } else {
    a[ind] = 2;
  }
  ll lst = 1;
  for (ll i = 1; i < n; i++) {
    ll ind = (y + i) % n;
    if (a[ind] != -1) {
      break;
    }
    if (lst == 1) {
      a[ind] = 0;
      lst = 0;
    } else {
      a[ind] = 1;
      lst = 1;
    }
  }
  lst = 1;
  for (ll i = 1; i < n; i++) {
    ll ind = (y - i) % n;
    if (ind < 0) {
      ind += n;
    }
    if (a[ind] != -1) {
      break;
    }
    if (lst == 1) {
      a[ind] = 0;
      lst = 0;
    } else {
      a[ind] = 1;
      lst = 1;
    }
  }
  for (ll x : a) {
    cout << x << " ";
  }
  cout << endl;
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
