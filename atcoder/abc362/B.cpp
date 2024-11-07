#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
struct Point {
  int x, y;
  Point() {}
  Point(int x, int y) : x(x), y(y) {}
  Point operator-(const Point &p) const { return Point(x - p.x, y - p.y); }
  int operator^(const Point &p) const { return x * p.y - y * p.x; }
  int operator*(const Point &p) const { return x * p.x + y * p.y; }
  int len2() const { return *this * *this; }
};
struct line {
  int a, b, c;
  line() {}
  line(int a, int b, int c) : a(a), b(b), c(c) {}
  line(const Point &p, const Point &q) {
    a = p.y - q.y;
    b = q.x - p.x;
    c = -a * p.x - b * p.y;
  }
  int operator*(const Point &p) const { return a * p.x + b * p.y + c; }
};
bool perp(const line &l, const line &m) { return l.a * m.a + l.b * m.b == 0; }
void solve() {
  Point a, b, c;
  cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y;
  line l(a, b), m(b, c), n(c, a);
  if (perp(l, m) || perp(m, n) || perp(n, l)) {
    cout << "Yes\n";
  } else {
    cout << "No\n";
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
