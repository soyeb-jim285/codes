#include <bits/stdc++.h>
#include <cmath>
using namespace std;
typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
ld const PI = acosl(-1);
struct pt {
  ld x, y;
};
ld dis(pt a, pt b) {
  return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}
void solve() {
  pt a, b;
  ll r1, r2;
  cin >> a.x >> a.y >> r1 >> b.x >> b.y >> r2;
  if (r1 < r2) {
    swap(a, b);
    swap(r1, r2);
  }
  ld d = dis(a, b);
  if (d >= r1 + r2) {
    cout << 0 << '\n';
    return;
  }
  if (d <= abs(r1 - r2)) {
    cout << min(r1, r2) * min(r1, r2) * acos(-1) << '\n';
    return;
  }
  if (d >= r1) {
    ld comd = (r1 + r2 - d) / 2;
    ld theta1 = acosl((r1 - comd) / r1);
    ld theta2 = acosl((r2 - comd) / r2);
    ld ans = r1 * r1 * theta1 + r2 * r2 * theta2 -
             r1 * r1 * sinl(2.0 * theta1) * 0.5 -
             r2 * r2 * sinl(2.0 * theta2) * 0.5;
    cout << ans << "\n";
  } else {
    ld theta1 = acosl((r1 * r1 + d * d - r2 * r2) / (2 * r1 * d));
    ld theta2 = 2 * PI - asinl(r1 * sin(theta1) / r2);
    ll ans = r1 * r1 * theta1 + r2 * r2 * theta2;
    cout << ans << "\n";
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(16);
  solve();
#ifdef ONPC
  cerr << endl
       << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif
}
