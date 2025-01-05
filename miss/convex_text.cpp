#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

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
void solve() {
  vector<P> pts;
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      pts.emplace_back(i, j);
    }
  }
  vector<P> hull = convexHull(pts, true);
  for (P p : hull) {
    cout << p << '\n';
  }
}
int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int t = 1;
  // cin >> t;
  while (t--) {
    solve();
  }
#ifdef ONPC
  cerr << endl
       << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif
}

