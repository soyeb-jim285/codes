#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
ll const N = 2e3 + 1;
struct point {
  ld x, y;
  point() {}
  point(ld x, ld y) : x(x), y(y) {}
  point operator-(point p) { return point(x - p.x, y - p.y); }
  ld operator*(point p) { return x * p.x + y * p.y; }
  bool operator<(point p) const { return x < p.x || (x == p.x && y < p.y); }
};
vector<point> vc(N);
vector<point> circles;
ld angle(point a, point b, point c) {
  point ab = b - a;
  point bc = c - b;
  ld ans = acosl((ab * bc) / (sqrtl(ab * ab) * sqrtl(bc * bc)));
  return ans;
}
ld angle(point a, point b) {
  ld ans = acosl(a * b / (sqrtl(a * a) * sqrtl(b * b)));
  return ans;
}
ld mindist(point a, point b, point e) {
  point ab = b - a;
  point be = e - b;
  point ae = e - a;
  ld ab_be = ab * be;
  ld ab_ae = ab * ae;
  ld ans = 0;
  // cout << "mindist" << endl;
  if (ab_be > 0) {
    ans = sqrtl(be * be);
    // cout << "eine 1" << endl;
  } else if (ab_ae < 0) {
    ans = sqrtl(ae * ae);
    // cout << ae.x << ' ' << ae.y << endl;
    // cout << "eine 2" << endl;
  } else {
    ld x1 = ab.x, y1 = ab.y;
    ld x2 = ae.x, y2 = ae.y;
    ld mod = sqrtl(x1 * x1 + y1 * y1);
    ans = fabsl(x1 * y2 - x2 * y1) / mod;
    // cout << "eine 2" << endl;
  }
  return ans;
}
void fn(point a, point b, point c, int n) {
  // cout << "---" << endl;
  // cout << a.x << ' ' << a.y << endl;
  // cout << b.x << ' ' << b.y << endl;
  // cout << c.x << ' ' << c.y << endl;
  // cout << "---" << endl;
  ld ang = angle(a, b, c);
  // cout << "ang = " << ang << endl;
  if (ang < 0)
    return;
  ld agg = angle(a, b);
  // cout << "agg = " << agg << endl;
  // cout << "ang = " << ang << endl;
  ang /= 2.0;
  ld d = 4.0 / sinl(ang);
  ld x = b.x + d * cosl(agg + ang);
  ld y = b.y + d * sinl(agg + ang);
  // cout << "x = " << x << " y = " << y << endl;
  for (int i = 0; i < n; i++) {
    // cout << "i = " << i << endl;
    // cout << mindist(vc[i], vc[(i + 1) % n], point(x, y)) << " " << endl;
    if (mindist(vc[i], vc[(i + 1) % n], point(x, y)) < 4.0)
      return;
  }
  circles.push_back(point(x, y));
}
ld dist(point a, point b) {
  return sqrtl((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}
void solve() {
  ll n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    ll x, y;
    cin >> x >> y;
    vc[i] = point(x, y);
  }
  reverse(vc.begin(), vc.begin() + n);
  vector<ld> ans(n, 0);
  // cout << "hoise" << endl;
  for (int i = 0; i < n; i++) {
    fn(vc[i], vc[(i + 1) % n], vc[(i + 2) % n], n);
  }
  // cout << "hoise2" << endl;
  for (int i = 0; i < circles.size(); i++) {
    for (int j = i + 1; j < circles.size(); j++) {
      ld dis = dist(circles[i], circles[j]);
      if (dis >= 8.0) {
        cout << setprecision(10) << circles[i].x << ' ' << circles[i].y << endl;
        cout << setprecision(10) << circles[j].x << ' ' << circles[j].y << endl;
        return;
      }
    }
  }
  cout << "impossible" << endl;
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
