#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
void solve() {
  ll n = 1e4, q = 2e5;
  cout << n << " " << q << "\n";
  for (int i = 0; i < n; i++) {
    cout << rnd() % (ll)1e5 << " " << rnd() % (ll)1e6 << " "
         << rnd() % (ll)1e9 + 1 << "\n";
  }
  while (q--) {
    cout << rnd() % (ll)1e9 << " " << rnd() % (ll)1e4 << "\n";
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();
#ifdef ONPC
  cerr << endl
       << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif
}
