#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define sz(a) ((int)((a).size()))
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
struct pt {
  ll x, y;
  pt operator-(pt p) { return {x - p.x, y - p.y}; }
  pt operator+(pt p) { return {x + p.x, y + p.y}; }
  bool operator<(pt p) const { return x < p.x || (x == p.x && y < p.y); }
  bool operator==(pt p) const { return x == p.x && y == p.y; }
  ll dot(pt p) const { return x * p.x + y * p.y; }
  ll cross(pt p) const { return x * p.y - y * p.x; }
  ll cross(pt a, pt b) const { return (a - *this).cross(b - *this); }
};
bool onSegment(pt s, pt e, pt p) {
  return p.cross(s, e) == 0 && (s - p).dot(e - p) <= 0;
}
typedef pt P;
vector<P> convexHull(vector<P> pts) {
  if (sz(pts) <= 1)
    return pts;
  sort(pts.begin(), pts.end());
  vector<P> h(sz(pts) + 1);
  int s = 0, t = 0;
  for (int it = 2; it--; s = --t, reverse(pts.begin(), pts.end())) {
    for (P p : pts) {
      while (t >= s + 2 && h[t - 2].cross(h[t - 1], p) < 0)
        t--;
      h[t++] = p;
    }
  }
  return {h.begin(), h.begin() + t - (t == 2 && h[0] == h[1])};
}
bool inPolygon(vector<pt> &p, pt a, bool strict = false) {
  int cnt = 0, n = sz(p);
  for (int i = 0; i < n; i++) {
    pt q = p[(i + 1) % n];
    if (onSegment(p[i], q, a))
      return !strict;
    // or: if (segDist(p[i], q, a) <= eps) return !strict;
    cnt ^= ((a.y < p[i].y) - (a.y < q.y)) * a.cross(p[i], q) > 0;
  }
  return cnt;
}
void solve() {
  ll bnd, stat;
  cin >> bnd >> stat;
  vector<pt> a(bnd);
  for (int i = 0; i < bnd; i++) {
    cin >> a[i].x >> a[i].y;
  }
  vector<pt> b(stat);
  for (int i = 0; i < stat; i++) {
    cin >> b[i].x >> b[i].y;
  }
  vector<pt> hull = convexHull(a);
  for (int i = 0; i < sz(hull); i++) {
    cout << hull[i].x << " " << hull[i].y << "\n";
  }
  cout << hull[0].x << " " << hull[0].y << "\n";
  for (int i = 0; i < stat; i++) {
    cout << b[i].x << " " << b[i].y << " is ";
    if (inPolygon(hull, b[i])) {
      cout << "unsafe!\n";
    } else {
      cout << "safe!\n";
    }
  }
  cout << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t, tt = 1;
  cin >> t;
  while (t--) {
    cout << "Case " << tt++ << "\n";
    solve();
  }
#ifdef ONPC
  cerr << endl
       << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif
}
