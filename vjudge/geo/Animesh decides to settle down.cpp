#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
const ld EPS = 1E-9;

struct pt {
  ld x, y;

  bool operator<(const pt &p) const {
    return x < p.x - EPS || (abs(x - p.x) < EPS && y < p.y - EPS);
  }
};

ld orientation(pt a, pt b, pt c) {
  ld v = a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y);
  if (v < 0)
    return -1; // clockwise
  if (v > 0)
    return +1; // counter-clockwise
  return 0;
}

bool cw(pt a, pt b, pt c, bool include_collinear) {
  ld o = orientation(a, b, c);
  return o < 0 || (include_collinear && o == 0);
}
bool collinear(pt a, pt b, pt c) { return orientation(a, b, c) == 0; }

void convex_hull(vector<pt> &a, bool include_collinear = false) {
  pt p0 = *min_element(a.begin(), a.end(), [](pt a, pt b) {
    return make_pair(a.y, a.x) < make_pair(b.y, b.x);
  });
  sort(a.begin(), a.end(), [&p0](const pt &a, const pt &b) {
    int o = orientation(p0, a, b);
    if (o == 0)
      return (p0.x - a.x) * (p0.x - a.x) + (p0.y - a.y) * (p0.y - a.y) <
             (p0.x - b.x) * (p0.x - b.x) + (p0.y - b.y) * (p0.y - b.y);
    return o < 0;
  });
  if (include_collinear) {
    int i = (int)a.size() - 1;
    while (i >= 0 && collinear(p0, a[i], a.back()))
      i--;
    reverse(a.begin() + i + 1, a.end());
  }

  vector<pt> st;
  for (int i = 0; i < (int)a.size(); i++) {
    while (st.size() > 1 &&
           !cw(st[st.size() - 2], st.back(), a[i], include_collinear))
      st.pop_back();
    st.push_back(a[i]);
  }
  a = st;
}
struct line {
  ld a, b, c;

  line() {}
  line(pt p, pt q) {
    a = p.y - q.y;
    b = q.x - p.x;
    c = -a * p.x - b * p.y;
    norm();
  }

  void norm() {
    ld z = sqrt(a * a + b * b);
    if (abs(z) > EPS)
      a /= z, b /= z, c /= z;
  }

  ld dist(pt p) const { return a * p.x + b * p.y + c; }
};

ld det(ld a, ld b, ld c, ld d) { return a * d - b * c; }

inline bool betw(ld l, ld r, ld x) {
  return min(l, r) <= x + EPS && x <= max(l, r) + EPS;
}

inline bool intersect_1d(ld a, ld b, ld c, ld d) {
  if (a > b)
    swap(a, b);
  if (c > d)
    swap(c, d);
  return max(a, c) <= min(b, d) + EPS;
}

bool intersect(pt a, pt b, pt c, pt d, pt &left, pt &right) {
  if (!intersect_1d(a.x, b.x, c.x, d.x) || !intersect_1d(a.y, b.y, c.y, d.y))
    return false;
  line m(a, b);
  line n(c, d);
  ld zn = det(m.a, m.b, n.a, n.b);
  if (abs(zn) < EPS) {
    if (abs(m.dist(c)) > EPS || abs(n.dist(a)) > EPS)
      return false;
    if (b < a)
      swap(a, b);
    if (d < c)
      swap(c, d);
    left = max(a, c);
    right = min(b, d);
    return true;
  } else {
    left.x = right.x = -det(m.c, m.b, n.c, n.b) / zn;
    left.y = right.y = -det(m.a, m.c, n.a, n.c) / zn;
    return betw(a.x, b.x, left.x) && betw(a.y, b.y, left.y) &&
           betw(c.x, d.x, left.x) && betw(c.y, d.y, left.y);
  }
}
ld area(vector<pt> &a) {
  ld ans = 0;
  for (int i = 0; i < a.size(); i++) {
    ans += a[i].x * a[(i + 1) % a.size()].y - a[i].y * a[(i + 1) % a.size()].x;
  }
  return abs(ans) / 2;
}
bool inside_point(pt q, vector<pt> &p) {
  bool c = 0;
  for (int i = 0; i < p.size(); i++) {
    int j = (i + 1) % p.size();
    if ((p[i].y <= q.y && q.y < p[j].y || p[j].y <= q.y && q.y < p[i].y) &&
        q.x < p[i].x + (p[j].x - p[i].x) * (q.y - p[i].y) / (p[j].y - p[i].y))
      c = !c;
  }
  return c;
}
vector<pt> intersec_poly(vector<pt> &a, vector<pt> &b) {
  vector<pt> c;
  for (int i = 0; i < a.size(); i++) {
    for (int j = 0; j < b.size(); j++) {
      pt left, right;
      if (intersect(a[i], a[(i + 1) % a.size()], b[j], b[(j + 1) % b.size()],
                    left, right)) {
        if (left.x != right.x || left.y != right.y) {
          c.push_back(left);
          c.push_back(right);
        } else
          c.push_back(left);
      }
    }
  }
  for (int i = 0; i < a.size(); i++) {
    if (inside_point(a[i], b))
      c.push_back(a[i]);
  }
  for (int i = 0; i < b.size(); i++) {
    if (inside_point(b[i], a))
      c.push_back(b[i]);
  }
  if (c.size() < 3)
    return c;
  convex_hull(c);
  return c;
}
void solve() {
  ll n;
  cin >> n;
  vector<vector<pt>> a(n);
  for (int i = 0; i < n; i++) {
    ll m;
    cin >> m;
    for (int j = 0; j < m; j++) {
      pt p;
      cin >> p.x >> p.y;
      a[i].push_back(p);
    }
  }
  vector<pt> c = a[0];
  for (int i = 1; i < n; i++) {
    c = intersec_poly(c, a[i]);
    if (c.size() < 3) {
      cout << "0\n";
      return;
    }
  }
  cout << area(c) << '\n';
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(16) << fixed;
  solve();
#ifdef ONPC
  cerr << endl
       << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif
}
