#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
void solve() {
  ll n = 10, q = 10;
  cout << n << " " << q << endl;
  for (int i = 0; i < n; i++) {
    cout << rnd() % 2;
  }
  cout << endl;
  for (int i = 0; i < q; i++) {
    ll k = rnd() % 2 + 1;
    cout << k << " ";
    if (k == 1) {
      ll pos = rnd() % n + 1;
      cout << pos << "\n";
    } else {
      ll k = rnd() % n + 1;
      cout << k << "\n";
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
