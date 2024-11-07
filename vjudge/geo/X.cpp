#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
struct pt {
  ld x, y;
  pt &operator-=(const pt &t) {
    x -= t.x;
    y -= t.y;
    return *this;
  }
  pt operator-(const pt &t) const { return pt(*this) -= t; }
};
struct crc {
  pt c;
  ld r;
};
ld dist(pt a, pt b) {
  return sqrtl(1.0 * (a.x - b.x) * (a.x - b.x) +
               1.0 * (a.y - b.y) * (a.y - b.y));
}
pt center_3pt(pt a, pt b) {
  ld B = a.x * a.x + a.y * a.y;
  ld C = b.x * b.x + b.y * b.y;
  ld D = a.x * b.y - a.y * b.x;
  return {(b.y * B - a.y * C) / (2 * D), (a.x * C - b.x * B) / (2 * D)};
}
crc circle_frm_3pt(pt a, pt b, pt c) {
  pt o = center_3pt(b - a, c - a);
  o.x += a.x;
  o.y += a.y;
  return {o, dist(o, a)};
}
void solve() {
  pt a, b, c;
  while (cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y) {
    crc ans = circle_frm_3pt(a, b, c);
    cout << "(x " << (ans.c.x < 0 ? "+" : "-") << " " << abs(ans.c.x)
         << ")^2 + (y " << (ans.c.y < 0 ? "+" : "-") << " " << abs(ans.c.y)
         << ")^2 = " << ans.r << "^2\n";
    cout << "x^2 + y^2 " << (ans.c.x < 0 ? "+" : "-") << " " << 2 * abs(ans.c.x)
         << "x " << (ans.c.y < 0 ? "+" : "-") << " " << 2 * abs(ans.c.y) << "y "
         << (ans.c.x * ans.c.x + ans.c.y * ans.c.y - ans.r * ans.r < 0 ? "- "
                                                                       : "+ ")
         << abs(ans.c.x * ans.c.x + ans.c.y * ans.c.y - ans.r * ans.r)
         << " = 0\n";
    cout << "\n";
  }
}
int main() {
  /* ios::sync_with_stdio(false); */
  /* cin.tie(nullptr); */
  cout << setprecision(3) << fixed;
  solve();
#ifdef ONPC
  cerr << endl
       << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif
}
