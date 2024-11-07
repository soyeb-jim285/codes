#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
struct pt {
  long long x, y;
  pt operator+(const pt &p) const { return pt{x + p.x, y + p.y}; }
  pt operator-(const pt &p) const { return pt{x - p.x, y - p.y}; }
  long long cross(const pt &p) const { return x * p.y - y * p.x; }
};

void reorder_polygon(vector<pt> &P) {
  size_t pos = 0;
  for (size_t i = 1; i < P.size(); i++) {
    if (P[i].y < P[pos].y || (P[i].y == P[pos].y && P[i].x < P[pos].x))
      pos = i;
  }
  rotate(P.begin(), P.begin() + pos, P.end());
}

vector<pt> minkowski(vector<pt> P, vector<pt> Q) {
  // the first vertex must be the lowest
  reorder_polygon(P);
  reorder_polygon(Q);
  // we must ensure cyclic indexing
  P.push_back(P[0]);
  P.push_back(P[1]);
  Q.push_back(Q[0]);
  Q.push_back(Q[1]);
  // main part
  vector<pt> result;
  size_t i = 0, j = 0;
  while (i < P.size() - 2 || j < Q.size() - 2) {
    result.push_back(P[i] + Q[j]);
    auto cross = (P[i + 1] - P[i]).cross(Q[j + 1] - Q[j]);
    if (cross >= 0 && i < P.size() - 2)
      ++i;
    if (cross <= 0 && j < Q.size() - 2)
      ++j;
  }
  return result;
}
long long cross(const pt &O, const pt &A, const pt &B) {
  return (A.x - O.x) * (B.y - O.y) - (A.y - O.y) * (B.x - O.x);
}

// Function to determine if a point P is inside a convex polygon given by
// vertices in counter-clockwise order
bool isInsideConvexPolygon(const vector<pt> &polygon, const pt &P) {
  int n = polygon.size();
  if (n < 3)
    return false; // Not a polygon

  // Handle edge cases for points outside the left-most or right-most triangles
  if (cross(polygon[0], polygon[1], P) < 0 ||
      cross(polygon[0], polygon[n - 1], P) > 0)
    return false;

  // Binary search to find the sector for point P
  int left = 1, right = n - 1;
  while (left + 1 < right) {
    int mid = (left + right) / 2;
    if (cross(polygon[0], polygon[mid], P) >= 0)
      left = mid;
    else
      right = mid;
  }
  // Check if point P is inside triangle formed by (polygon[0], polygon[left],
  // polygon[left + 1])
  return cross(polygon[left], polygon[left + 1], P) >= 0;
}
void solve() {
  ll n1, n2, n3;
  vector<pt> poly1, poly2, poly3;
  cin >> n1;
  for (int i = 0; i < n1; i++) {
    ll x, y;
    cin >> x >> y;
    poly1.push_back({x, y});
  }
  cin >> n2;
  for (int i = 0; i < n2; i++) {
    ll x, y;
    cin >> x >> y;
    poly2.push_back({x, y});
  }
  cin >> n3;
  for (int i = 0; i < n3; i++) {
    ll x, y;
    cin >> x >> y;
    poly3.push_back({x, y});
  }
  vector<pt> poly12 = minkowski(poly1, poly2);
  vector<pt> poly123 = minkowski(poly12, poly3);
  ll q;
  cin >> q;
  while (q--) {
    ll x, y;
    cin >> x >> y;
    pt p = {3 * x, 3 * y};
    if (isInsideConvexPolygon(poly123, p)) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
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
