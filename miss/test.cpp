#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
void solve() {
  ll t = 1;
  cout << t << "\n";
  while (t--) {
    ll n = rnd() % 10 + 1, k = rnd() % 10 + 1;
    cout << n << " " << k << "\n";
    for (int i = 0; i < n; i++) {
      cout << rnd() % 50 + 1 << " ";
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
