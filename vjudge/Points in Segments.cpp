#include <bits/stdc++.h>
#include <math.h>
using namespace std;

#define sz(a) ((int)((a).size()))

typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
void solve() {
  ll n, q;
  cin >> n >> q;
  vector<ll> v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }
  while (q--) {
    ll l, r;
    cin >> l >> r;
    auto ll = lower_bound(v.begin(), v.end(), l) - v.begin();
    auto rr = upper_bound(v.begin(), v.end(), r) - v.begin();
    cout << rr - ll << '\n';
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);
  int t, tt = 1;
  cin >> t;
  while (t--) {
    cout << "Case " << tt++ << ": \n";
    solve();
  }
#ifdef ONPC
  cerr << endl
       << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif
}
