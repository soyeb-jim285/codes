#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
ld PI = 3.14159265358979323846;

template <class T> int sgn(T x) { return (x > 0) - (x < 0); }
template <class T> struct Point {
  typedef Point P;
  T x, y;
  explicit Point(T x = 0, T y = 0) : x(x), y(y) {}
  bool operator<(P p) const { return tie(x, y) < tie(p.x, p.y); }
  bool operator==(P p) const { return tie(x, y) == tie(p.x, p.y); }
  P operator+(P p) const { return P(x + p.x, y + p.y); }
  P operator-(P p) const { return P(x - p.x, y - p.y); }
  P operator*(T d) const { return P(x * d, y * d); }
  P operator/(T d) const { return P(x / d, y / d); }
  T dot(P p) const { return x * p.x + y * p.y; }
  T cross(P p) const { return x * p.y - y * p.x; }
  T cross(P a, P b) const { return (a - *this).cross(b - *this); }
  T dist2() const { return x * x + y * y; }
  double dist() const { return sqrt((double)dist2()); }
  // angle to x-axis in interval [-pi, pi]
  double angle() const { return atan2(y, x); }
  P unit() const { return *this / dist(); } // makes dist()=1
  P perp() const { return P(-y, x); }       // rotates +90 degrees
  P normal() const { return perp().unit(); }
  // returns point rotated 'a' radians ccw around the origin
  P rotate(double a) const {
    return P(x * cos(a) - y * sin(a), x * sin(a) + y * cos(a));
  }
  friend ostream &operator<<(ostream &os, P p) {
    return os << "(" << p.x << "," << p.y << ")";
  }
};
typedef Point<ll> P;
vector<P> convexHull(vector<P> pts, bool allow_collinear = false) {
  if (sz(pts) <= 1)
    return pts;
  sort(all(pts));
  pts.erase(unique(all(pts), [&](const P &a, const P &b) { return a == b; }),
            pts.end());
  vector<P> hull;
  auto condition = [&](const P &a, const P &b, const P &c) -> bool {
    ll cross = a.cross(b, c);
    if (allow_collinear)
      return cross < 0;
    else
      return cross <= 0;
  };
  for (const P &p : pts) {
    while (sz(hull) >= 2 &&
           condition(hull[sz(hull) - 2], hull[sz(hull) - 1], p))
      hull.pop_back();
    hull.push_back(p);
  }
  int lower_size = sz(hull) + 1;
  for (int i = sz(pts) - 1; i >= 0; --i) {
    const P &p = pts[i];
    while (sz(hull) >= lower_size &&
           condition(hull[sz(hull) - 2], hull[sz(hull) - 1], p))
      hull.pop_back();
    hull.push_back(p);
  }
  hull.pop_back();
  return hull;
}

ld len(Point<ll> p1, Point<ll> p2) {
  return sqrt(1.0 * (p1.x - p2.x) * (p1.x - p2.x) +
              1.0 * (p1.y - p2.y) * (p1.y - p2.y));
}

ld angle(Point<ll> x, Point<ll> y, Point<ll> z) {
  ld a = len(x, y);
  ld b = len(y, z);
  ld c = len(z, x);
  if (a * b == 0)
    return 0;
  ld res = acos((a * a + b * b - c * c) / (2 * a * b)) * 180 / PI;
  return res;
}

void solve() {
  ll n;
  cin >> n;
  vector<Point<ll>> cords(n);
  for (int i = 0; i < n; i++) {
    cin >> cords[i].x >> cords[i].y;
  }
  if (n < 2) {
    cout << "0\n";
    return;
  }
  vector<Point<ll>> hall = convexHull(cords);
  n = sz(hall);
  if (n < 2) {
    cout << "0\n";
    return;
  }
  ld mn = 180;
  for (int i = 0; i < n; i++) {
    ll ind1 = (i + n - 1) % n;
    ll ind3 = (i + 1) % n;
    // cout << hall[ind1]<< " " <<  hall[i]<< "  "<<  hall[ind3] << " ";
    // cout << angle(hall[ind1], hall[i], hall[ind3]) << "----\n";
    mn = min(mn, angle(hall[ind1], hall[i], hall[ind3]));
  }
  cout << mn << "\n";
}
int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int t = 1, tt = 1;
  cin >> t;
  cout << setprecision(12) << fixed;
  while (t--) {
    cout << "Case " << tt++ << ": ";
    solve();
  }
#ifdef ONPC
  cerr << endl
       << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif
}
