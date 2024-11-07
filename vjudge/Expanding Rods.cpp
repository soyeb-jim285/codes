#include <bits/stdc++.h>
#include <math.h>
using namespace std;

#define sz(a) ((int)((a).size()))

typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
bool fn(ld mid, ld d, ld dd) {
  ld r = mid / 2 + d * d / (8 * mid);
  ld theta = acos(1 - mid / r);
  ld length = 2 * r * theta;
  // cout << length << " " << r << " " << theta << " " << dd << '\n';
  if (length > dd)
    return 1;
  else
    return 0;
}
void solve() {
  ld d, n, c;
  cin >> d >> n >> c;
  ld dd = (1 + n * c) * d;
  ld low = 0, high = dd;
  ld eps = 1e-6;
  while (high - low > eps) {
    ld mid = (low + high) / 2;
    if (fn(mid, d, dd))
      high = mid;
    else
      low = mid;
  }
  // cout << fn(61.3289915, d, dd) << "-----\n";
  cout << low << '\n';
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);
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
