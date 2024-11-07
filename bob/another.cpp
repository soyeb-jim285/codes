#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
struct point {
  ll x, y;
  bool operator==(point p) { return x == p.x && y == p.y; }
};
ld area(point a, point b, point c) {
  return abs((b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x)) / 2.0;
}
ld dist(point a, point b) {
  return sqrt(1.0 * (a.x - b.x) * (a.x - b.x) +
              1.0 * (a.y - b.y) * (a.y - b.y));
}
ld semi_perimeter(point a, point b, point c) {
  return (dist(a, b) + dist(b, c) + dist(c, a)) / 2.0;
}
void solve() {
  ll l;
  cin >> l;
  ld r = l / 2.0;
  point A, B, C;
  cin >> A.x >> A.y >> B.x >> B.y >> C.x >> C.y;
  if (A == B || B == C || C == A) {
    cout << "0\n";
    return;
  }
  ld triangle_area = area(A, B, C);
  ld s = semi_perimeter(A, B, C);
  ld r_in = triangle_area / s;

  if (r_in < r) {
    cout << "0\n";
    return;
  }
  ld corner_area = r * r * s / r_in;
  cout << setprecision(6) << fixed << triangle_area - corner_area + r * r * M_PI
       << '\n';
}
int main() {
  // ios_base::sync_with_stdio(false);
  // cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--)
    solve();
#ifdef ONPC
  cerr << endl
       << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif
}
