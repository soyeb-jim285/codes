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
  map<vector<ll>, ll> a, b, c, all;
  vector<ll> vc(n);
  for (int i = 0; i < n; i++) {
    cin >> vc[i];
  }
  ll cnt = 0;
  for (int i = 0; i < n - 2; i++) {
    a[{vc[i], vc[i + 1]}]++;
    b[{vc[i], vc[i + 2]}]++;
    c[{vc[i + 1], vc[i + 2]}]++;
    all[{vc[i], vc[i + 1], vc[i + 2]}]++;
  }
  for (auto ic : a) {
    cnt += ic.second * (ic.second - 1) / 2;
  }
  for (auto ic : b) {
    cnt += ic.second * (ic.second - 1) / 2;
  }
  for (auto ic : c) {
    cnt += ic.second * (ic.second - 1) / 2;
  }
  for (auto ic : all) {
    cnt -= 3 * ic.second * (ic.second - 1) / 2;
  }
  cout << cnt << '\n';
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
