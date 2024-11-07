#include <bits/stdc++.h>
using namespace std;

#define sz(a) ((int)((a).size()))

typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
ld const pi = acosl(-1);

void solve() {
  ld D, d, H;
  cin >> D >> d >> H;
  D /= 2;
  d -= D;
  ld r = sqrtl(D * D - d * d);
  ld eps = 1e-2;
  ld spare = 4 * pi * D * D * D / 3;
  ld cyl = pi * r * r * H;
  if (abs(spare - cyl) < eps) {
    cout << "Yes\n";
  } else {
    cout << "No\n";
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
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
