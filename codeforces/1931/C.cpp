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
  vector<ll> vc(n);
  for (int i = 0; i < n; i++) {
    cin >> vc[i];
  }
  ll fst = vc[0], lst = vc[n - 1];
  ll frn = 0, mn = 1e18;
  for (int i = 0; i < n; i++) {
    if (vc[i] != fst) {
      frn = i;
      break;
    }
  }
  for (int i = n - 1; i >= 0; i--) {
    if (vc[i] != fst) {
      ll k = n - 1 - i;
      mn = min(mn, n - frn - k);
      break;
    }
  }
  for (int i = 0; i < n; i++) {
    if (vc[i] != lst) {
      frn = i;
      break;
    }
  }
  for (int i = n - 1; i >= 0; i--) {
    if (vc[i] != lst) {
      ll k = n - 1 - i;
      mn = min(mn, n - frn - k);
      break;
    }
  }
  if (mn == 1e18)
    cout << "0\n";
  else {
    cout << mn << endl;
  }
}
int main() {
  ios::sync_with_stdio(false);
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
