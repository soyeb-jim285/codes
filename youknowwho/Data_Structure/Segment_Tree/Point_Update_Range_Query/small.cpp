#include <bits/stdc++.h>
#include <utility>
using namespace std;
typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
void solve() {
  ll n = rnd() % (ll)1e5 + 1, q = rnd() % (ll)1e5 + 1;
  cout << n << " " << q << "\n";
  for (int i = 0; i < n; i++) {
    cout << rnd() % (ll)1e9 + 1 << " ";
  }
  cout << "\n";
  while (q--) {
    ll type = rnd() % 2 + 1;
    cout << type << " ";
    if (type == 1) {
      cout << rnd() % n + 1 << " " << rnd() % (ll)1e9 + 1 << "\n";
    } else {
      ll l = rnd() % n + 1, r = rnd() % n + 1;
      if (l > r)
        swap(l, r);
      cout << l << " " << r << "\n";
    }
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
