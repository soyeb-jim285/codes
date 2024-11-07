#include <bits/stdc++.h>
using namespace std;

#define sz(a) ((int)((a).size()))

typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
ld eps = 1e-7;
void solve() {
  ld x, y, c;
  cin >> x >> y >> c;
  ld l = 0, r = min(x, y);
  while (r - l > eps) {
    ld mid = (l + r) / 2;
    ld h1 = sqrt(x * x - mid * mid);
    ld h2 = sqrt(y * y - mid * mid);
    ld c1 = h1 * h2 / (h1 + h2);
    if (c1 > c) {
      l = mid;
    } else {
      r = mid;
    }
  }
  cout << l << "\n";
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(16);
  int t, tt = 1;
  cin >> t;
  while (t--) {
    cout << "Case " << tt++ << ": ";
    solve();
  }
#ifdef ONPC
  cerr << endl
       << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif
}
