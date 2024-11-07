#include <bits/stdc++.h>
using namespace std;

#define sz(a) ((int)((a).size()))

typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
void solve() {
  ll n;
  cin >> n;
  vector<ll> a(n);
  for (ll &x : a)
    cin >> x;
  ll mx = -1;
  ll sum = 0, def = 0;
  for (int i = 0; i < n; i++) {
    if (mx != -1 && a[i] < mx) {
      sum += mx - a[i];
      def = max(def, mx - a[i]);
    }
    mx = max(mx, a[i]);
  }
  sum += def;
  cout << sum << endl;
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
/*
 * 2 1 4 7 6
 * 2 2 4 7 6
 * 344 12  37  60  311 613 365 328 675
 * 344 344 344 344 344 613 613 613 675
 * 0   332 307 284 33  0   248 285 0
 * 5 4 4 3 2
 * 4 4 3 2 1
 * 4 3 2 1 0
 */
