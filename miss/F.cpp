#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
struct Pt {
  ll x, y;
  Pt operator-(Pt p) { return {x - p.x, y - p.y}; }
  Pt operator+(Pt p) { return {x + p.x, y + p.y}; }
  ll operator*(Pt p) { return x * p.y - y * p.x; }
  Pt operator*(ll c) { return {x * c, y * c}; }
  Pt operator/(ll c) { return {x / c, y / c}; }
  bool operator==(Pt p) { return x == p.x && y == p.y; }
};
struct Line {
  ll a, b, c;
};
Line getLine(Pt p1, Pt p2) {
  ll a = p2.y - p1.y;
  ll b = p1.x - p2.x;
  ll c = -a * p1.x - b * p1.y;
  return {a, b, c};
}
Pt origin;
bool compareByAngle(Pt p1, Pt p2) {
  ld angle1 = atan2(p1.y - origin.y, p1.x - origin.x);
  ld angle2 = atan2(p2.y - origin.y, p2.x - origin.x);

  return angle1 < angle2;
}
int orientation(Pt a, Pt b, Pt c) {
  ll val = (b - a) * (c - b);
  if (val == 0)
    return 0;
  return val > 0 ? 1 : -1;
}
Pt LineSegmentIntersection(Line &L, Pt &p1, Pt &p2) {
  ll a = L.a, b = L.b, c = L.c;
  ll x1 = p1.x, y1 = p1.y, x2 = p2.x, y2 = p2.y;
  ll A = y2 - y1;
  ll B = x1 - x2;
  ll C = A * x1 + B * y1;
  ll det = a * B - A * b;
  if (det == 0)
    return {(ll)1e7, (ll)1e7};
  return {(B * c - b * C) / det, (a * C - A * c) / det};
}
bool collinear(Pt a, Pt b, Pt c) { return (b - a) * (c - b) == 0; }
bool isPointOnSegment(Pt A, Pt B, Pt P) {
  if ((B - A) * (P - A) != 0) {
    return false;
  }
  return min(A.x, B.x) <= P.x && P.x <= max(A.x, B.x) && min(A.y, B.y) <= P.y &&
         P.y <= max(A.y, B.y);
}
bool checkSolve(Pt Origin, Pt ans, set<int> &sides, vector<Pt> &main_pts) {
  Line L = getLine(Origin, ans);
  vector<Pt> pts;
  for (auto s : sides) {
    Pt p1 = main_pts[s];
    Pt p2 = main_pts[(s + 1) % main_pts.size()];
    Pt inter = LineSegmentIntersection(L, p1, p2);
    if (inter == Pt{(ll)1e7, (ll)1e7})
      return false;
    pts.push_back(inter);
  }
  if (pts.size() == 2) {
    if (isPointOnSegment(pts[0], pts[1], ans)) {
      return false;
    }
  }
  return true;
}
void solve() {
  ll n;
  cin >> n;
  vector<Pt> pts(n);
  map<pair<int, int>, int> cnt;
  ll mn_x = 1e9, mn_y = 1e9, mx_x = -1e9, mx_y = -1e9;
  for (int i = 0; i < n; i++) {
    cin >> pts[i].x >> pts[i].y;
    pts[i].x *= 2;
    pts[i].y *= 2;
    mn_x = min(mn_x, pts[i].x);
    mn_y = min(mn_y, pts[i].y);
    mx_x = max(mx_x, pts[i].x);
    mx_y = max(mx_y, pts[i].y);
    cnt[{pts[i].x, pts[i].y}] = i;
  }
  origin = {(mx_x + mn_x) / 2, (mx_y + mn_y) / 2};
  vector<Pt> main_pts = pts;
  sort(pts.begin(), pts.end(), compareByAngle);
  // for (int i = 0; i < n; i++) {
  //   cout << pts[i].x / 2 << ' ' << pts[i].y / 2 << '\n';
  // }
  set<int> sides;
  vector<ll> vals(n, 0);
  for (int i = 0; i < n; i++) {
    if (orientation(pts[0], origin, pts[i]) == 0) {
      vals[cnt[{pts[i].x, pts[i].y}]] = 0;
    } else if (orientation(pts[0], origin, pts[i]) == 1) {
      vals[cnt[{pts[i].x, pts[i].y}]] = 1;
    } else {
      vals[cnt[{pts[i].x, pts[i].y}]] = -1;
    }
  }
  ll intcnt = 0;
  for (int i = 0; i < n; i++) {
    ll samne = (i + 1) % n;
    if (vals[i] * vals[samne] < 0) {
      sides.insert(i);
      intcnt++;
    }
  }
  if (intcnt < 2) {
    cout << origin.x << "/2" << ' ' << origin.y << "/2" << " " << pts[0].x / 2
         << ' ' << pts[0].y / 2 << "\n";
    return;
  }
  if (intcnt == 2) {
    Pt ans = pts[0] + pts[1];
    ans = ans / 2;
    if (!collinear(origin, pts[0], ans) && !collinear(origin, pts[1], ans)) {
      cout << origin.x << "/2" << ' ' << origin.y << "/2" << " " << ans.x
           << "/2 " << ans.y << "/2\n";
      return;
    }
  }
  // for (auto p : vals) {
  //   cout << p << ' ';
  // }
  // cout << '\n';
  // cout << intcnt << '\n';
  for (int i = 1; i < n; i++) {
    ll indx = cnt[{pts[i].x, pts[i].y}];
    ll samne = (indx + 1) % n;
    ll prev = indx - 1;
    if (prev < 0)
      prev = n - 1;
    if (vals[indx] * vals[samne] < 0) {
      sides.erase(indx);
      intcnt--;
    }
    if (vals[prev] * vals[indx] < 0) {
      sides.erase(prev);
      intcnt--;
    }
    // cout << indx << " " << intcnt << " aa\n";
    indx = (indx + n / 2) % n;
    samne = (indx + 1) % n;
    prev = indx - 1;
    if (prev < 0)
      prev = n - 1;
    if (prev < 0)
      prev = n - 1;
    if (vals[indx] * vals[samne] < 0) {
      sides.erase(indx);
      intcnt--;
    }
    if (vals[prev] * vals[indx] < 0) {
      sides.erase(prev);
      intcnt--;
    }
    // cout << intcnt << " bb\n";
    vals[cnt[{pts[i].x, pts[i].y}]] = 0;
    vals[indx] = 0;
    if (orientation(pts[i], origin, pts[i - 1]) == 0) {
      vals[cnt[{pts[i - 1].x, pts[i - 1].y}]] = 0;
    } else if (orientation(pts[i], origin, pts[i - 1]) == 1) {
      vals[cnt[{pts[i - 1].x, pts[i - 1].y}]] = 1;
    } else {
      vals[cnt[{pts[i - 1].x, pts[i - 1].y}]] = -1;
    }
    ll old_indx = cnt[{pts[i - 1].x, pts[i - 1].y}];
    ll samne_old = (old_indx + 1) % n;
    ll prev_old = old_indx - 1;
    if (prev_old < 0)
      prev_old = n - 1;
    if (vals[old_indx] * vals[samne_old] < 0) {
      sides.insert(old_indx);
      intcnt++;
    }
    if (vals[prev_old] * vals[old_indx] < 0) {
      sides.insert(prev_old);
      intcnt++;
    }
    // cout << intcnt << " cc\n";
    old_indx = (old_indx + n / 2) % n;
    samne_old = (old_indx + 1) % n;
    prev_old = old_indx - 1;
    if (prev_old < 0)
      prev_old = n - 1;
    if (orientation(pts[i], origin, main_pts[old_indx]) == 0) {
      vals[old_indx] = 0;
    } else if (orientation(pts[i], origin, main_pts[old_indx]) == 1) {
      vals[old_indx] = 1;
    } else {
      vals[old_indx] = -1;
    }
    if (vals[old_indx] * vals[samne_old] < 0) {
      sides.insert(old_indx);
      intcnt++;
    }
    if (vals[prev_old] * vals[old_indx] < 0) {
      sides.insert(prev_old);
      intcnt++;
    }
    // cout << intcnt << " dd\n";
    // for (auto p : vals) {
    //   cout << p << ' ';
    // }
    // cout << '\n';
    // cout << intcnt << '\n';
    if (intcnt < 2) {
      cout << origin.x << "/2" << ' ' << origin.y << "/2" << " " << pts[i].x / 2
           << ' ' << pts[i].y / 2 << "\n";
      return;
    }
    if (intcnt == 2) {
      // cout << "Paisi\n";
      Pt ans = pts[i] + pts[(i + 1) % n];
      ans = ans / 2;
      if (!collinear(origin, pts[i], ans) &&
          !collinear(origin, pts[(i + 1) % n], ans)) {
        cout << origin.x << "/2" << ' ' << origin.y << "/2" << " " << ans.x
             << "/2 " << ans.y << "/2\n";
        return;
      }
    }
  }
  cout << "impossible\n";
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
