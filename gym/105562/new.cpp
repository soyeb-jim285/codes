#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef __int128_t lll;
typedef long double ld;
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

ll area(vector<Point<ld>> &p) {
  ld res = 0;
  for (int i = 0; i < sz(p); i++) {
    Point<ld> a = i ? p[i - 1] : p.back();
    Point<ld> b = p[i];
    res += (a.x - b.x) * (a.y + b.y);
  }
  return abs(res);
}

void solve() {
  ll n;
  cin >> n;
  vector<Point<ld>> cords(n);
  for (int i = 0; i < n; i++) {
    cin >> cords[i].x >> cords[i].y;
  }
  ll polyogn = area(cords);
  vector<Point<ld>> pre(n + 1), suf(n + 1);
  pre[0].x = 0;
  pre[0].y = 0;
  suf[n].x = 0;
  suf[n].y = 0;
  for (int i = 0; i < n; i++) {
    pre[i + 1] = pre[i] + cords[i];
  }
  for (int i = n - 1; i >= 0; i--) {
    suf[i] = suf[i + 1] + cords[i];
  }
  // for (int i = 0; i <= n; i++) {
  //   // cout << pre[i] << " " << suf[i] << "\n";
  // }
  ld sum = 0;
  for (ll i = 0; i < n; i++) {
    Point<ld> a = cords[i] * i - pre[i];
    Point<ld> b = suf[i] - cords[i] * (n - i);
    sum += abs(a.cross(b)) / (ld)polyogn;
    // cout << a << " " << b << " " << a.cross(b) << "\n";
  }
  // cout << sum << " " << polyogn << "\n";
  cout << sum << "\n";
}
int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  cout << setprecision(16) << fixed;
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
