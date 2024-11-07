#include <bits/stdc++.h>
#include <cmath>
using namespace std;
typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
struct pt {
  ll x, y;
};
struct line {
  ll a, b, c;
};
ld dist(pt a, pt b) {
  return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}
bool on_line(pt a, pt b, pt c) { return dist(a, b) >= dist(a, c) + dist(b, c); }
ll det(ll a, ll b, ll c, ll d) { return a * d - b * c; }
bool boundary(pt a, pt b, pt c) {
  if ((b.y - a.y) * (c.x - b.x) == (c.y - b.y) * (b.x - a.x)) {
    if (on_line(a, b, c))
      return 1;
    else
      return 0;
  } else
    return 0;
}
line Line(pt a, pt b) {
  line l;
  l.a = a.y - b.y;
  l.b = b.x - a.x;
  l.c = -l.a * a.x - l.b * a.y;
  return l;
}
line perpLine(line l, pt p) {
  line res;
  res.a = l.b;
  res.b = -l.a;
  res.c = -res.a * p.x - res.b * p.y;
  return res;
}
bool intersecting(line l1, line l2, pt &res) {
  ll zn = det(l1.a, l1.b, l2.a, l2.b);
  if (zn == 0)
    return 0;
  res.x = -det(l1.c, l1.b, l2.c, l2.b) * 1.0 / zn;
  res.y = -det(l1.a, l1.c, l2.a, l2.c) * 1.0 / zn;
  return 1;
}
void solve() {
  ll n, m;
  cin >> n >> m;
  vector<pt> polygon(n);
  for (int i = 0; i < n; i++) {
    cin >> polygon[i].x >> polygon[i].y;
  }
  vector<pt> points(m);
  for (int i = 0; i < m; i++) {
    cin >> points[i].x >> points[i].y;
    for (int j = 0; j < n; j++) {
      if (boundary(polygon[j], polygon[(j + 1) % n], points[i])) {
        cout << "BOUNDARY\n";
        break;
      }
    }
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
