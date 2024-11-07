#include <bits/stdc++.h>
using namespace std;

#define sz(a) ((int)((a).size()))

typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

struct pt {
  ld x, y;
};

struct line {
  ld a, b, c;
};

const ld EPS = 1e-9;

ld det(ld a, ld b, ld c, ld d) { return a * d - b * c; }

bool betw(ld l, ld r, ld x) {
  return min(l, r) <= x + EPS && x <= max(l, r) + EPS;
}
bool equa(pt a, pt b) { return abs(a.x - b.x) < EPS && abs(a.y - b.y) < EPS; }
bool intersect(line m, line n, pt &res) {
  ld zn = det(m.a, m.b, n.a, n.b);
  if (abs(zn) < EPS)
    return false;
  res.x = -det(m.c, m.b, n.c, n.b) / zn;
  res.y = -det(m.a, m.c, n.a, n.c) / zn;
  return true;
}

void solve() {
  ld a, b, c, d;
  cin >> a >> b >> c >> d;
  ld r;
  cin >> r;
  vector<pt> conv;
  pt p;
  p.x = r, p.y = r;
  conv.push_back(p);
  p.x = -r, p.y = r;
  conv.push_back(p);
  p.x = -r, p.y = -r;
  conv.push_back(p);
  p.x = r, p.y = -r;
  conv.push_back(p);
  for (int ii = 0; ii < 3; ii++) {
    ld aa, bb, cc;
    string s;
    cin >> aa >> bb >> s >> cc;
    cc = -cc;
    line m;
    m.a = aa;
    m.b = bb;
    m.c = cc;
    vector<pt> tmp, tmp1;
    for (int i = 0; i < sz(conv); i++) {
      int num = sz(conv);
      line n;
      tmp.push_back(conv[i]);
      n.a = conv[(i + 1) % num].y - conv[i].y;
      n.b = conv[i].x - conv[(i + 1) % num].x;
      n.c = -conv[i].x * conv[(i + 1) % num].y +
            conv[i].y * conv[(i + 1) % num].x;
      if (intersect(m, n, p)) {
        if (betw(conv[i].x, conv[(i + 1) % num].x, p.x) &&
            betw(conv[i].y, conv[(i + 1) % num].y, p.y) && !equa(p, conv[i]) &&
            !equa(p, conv[(i + 1) % num])) {
          tmp.push_back(p);
        }
      }
    }
    // cout << sz(tmp) << endl;
    // for (int i = 0; i < sz(tmp); i++) {
    //   cout << fixed << setprecision(3) << tmp[i].x << " " << tmp[i].y <<
    //   endl;
    // }
    for (int i = 0; i < sz(tmp); i++) {
      if (s == ">=") {
        if (aa * tmp[i].x + bb * tmp[i].y + cc >= -EPS)
          tmp1.push_back(tmp[i]);
      } else if (s == "<=") {
        if (aa * tmp[i].x + bb * tmp[i].y + cc <= EPS)
          tmp1.push_back(tmp[i]);
      } else {
        if (aa * tmp[i].x + bb * tmp[i].y + cc < EPS &&
            aa * tmp[i].x + bb * tmp[i].y + cc > -EPS)
          tmp1.push_back(tmp[i]);
      }
    }
    conv = tmp1;
    // cout << sz(conv) << endl;
    // for (int i = 0; i < sz(conv); i++) {
    //   cout << fixed << setprecision(3) << conv[i].x << " " << conv[i].y <<
    //   endl;
    // }
  }
  // cout << sz(conv) << endl;
  // for (int i = 0; i < sz(conv); i++) {
  //   cout << fixed << setprecision(3) << conv[i].x << " " << conv[i].y <<
  //   endl;
  // }
  if (sz(conv) == 0) {
    cout << "No Solution" << endl;
    return;
  }
  ld ans;
  if (d) {
    ans = -1e18;
    for (int i = 0; i < sz(conv); i++) {
      ans = max(ans, a * conv[i].x + b * conv[i].y + c);
    }
  } else {
    ans = 1e18;
    for (int i = 0; i < sz(conv); i++) {
      ans = min(ans, a * conv[i].x + b * conv[i].y + c);
    }
  }
  cout << fixed << setprecision(3) << ans << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--)
    solve();
#ifdef ONPC
  cerr << endl
       << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif
}

/*
1
5 6 7 1
20
48.58 28.86 <= 90
45.48 -21.92 >= 2
49.31 -13.24 <= -517

*/
