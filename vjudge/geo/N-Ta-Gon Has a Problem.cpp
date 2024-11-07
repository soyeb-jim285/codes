#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
ld eps = 1e-8;
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
bool inside(crc a, pt b) { return dist(a.c, b) < a.r + eps; }
pt center_3pt(pt a, pt b) {
  ld B = a.x * a.x + a.y * a.y;
  ld C = b.x * b.x + b.y * b.y;
  ld D = a.x * b.y - a.y * b.x;
  return {(b.y * B - a.y * C) / (2 * D), (a.x * C - b.x * B) / (2 * D)};
}
pt center(pt a, pt b) {
  pt c;
  c.x = (a.x + b.x) / 2;
  c.y = (a.y + b.y) / 2;
  return c;
}
crc circle_frm_3pt(pt a, pt b, pt c) {
  pt o = center_3pt(b - a, c - a);
  o.x += a.x;
  o.y += a.y;
  return {o, dist(o, a)};
}
crc cirlce_frm_2pt(pt a, pt b) {
  pt o = center(a, b);
  return {o, dist(a, b) / 2};
}
bool valid_circle(crc a, vector<pt> &b) {
  for (auto &i : b) {
    if (!inside(a, i)) {
      return false;
    }
  }
  return true;
}
crc min_crc(vector<pt> &a) {
  if (a.size() == 0) {
    return {{0, 0}, 0};
  }
  if (a.size() == 1) {
    return {a[0], 0};
  }
  if (a.size() == 2) {
    return cirlce_frm_2pt(a[0], a[1]);
  }
  for (int i = 0; i < 3; i++) {
    for (int j = i + 1; j < 3; j++) {
      crc c = cirlce_frm_2pt(a[i], a[j]);
      if (valid_circle(c, a)) {
        return c;
      }
    }
  }
  return circle_frm_3pt(a[0], a[1], a[2]);
}
crc welzl_random(vector<pt> &a, vector<pt> b, ll n) {
  if (n == 0 || b.size() == 3) {
    return min_crc(b);
  }
  ll i = rnd() % n;
  swap(a[i], a[n - 1]);
  crc c = welzl_random(a, b, n - 1);
  if (inside(c, a[n - 1])) {
    return c;
  }
  b.push_back(a[n - 1]);
  return welzl_random(a, b, n - 1);
}
crc welzl(vector<pt> &a) {
  vector<pt> b;
  shuffle(a.begin(), a.end(), rnd);
  return welzl_random(a, b, a.size());
}
void solve() {
  ld n, l;
  cin >> n >> l;
  ll m;
  cin >> m;
  vector<pt> a(m);
  for (int i = 0; i < m; i++) {
    cin >> a[i].x >> a[i].y;
  }
  crc c = welzl(a);
  ld theta = acosl(-1) / n;
  ld base = 2 * c.r * tanl(theta);
  cout << base / l << '\n';
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
