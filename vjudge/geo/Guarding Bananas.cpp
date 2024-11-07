#include <bits/stdc++.h>
using namespace std;

#define sz(a) ((int)((a).size()))

typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
ld const PI = acosl(-1);
struct pt {
  ll x, y;
};

ll orientation(pt a, pt b, pt c) {
  ll v = a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y);
  if (v < 0)
    return -1; // clockwise
  if (v > 0)
    return +1; // counter-clockwise
  return 0;
}

bool cw(pt a, pt b, pt c, bool include_collinear) {
  ll o = orientation(a, b, c);
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
ll dot(pt a, pt b) { return a.x * b.x + a.y * b.y; }
ll norm(pt a) { return dot(a, a); }
ld abs(pt a) { return sqrt(norm(a)); }
ld angle(pt a, pt b, pt c) {
  ld x = dot({a.x - b.x, a.y - b.y}, {c.x - b.x, c.y - b.y});
  ld y = abs({a.x - b.x, a.y - b.y}) * abs({c.x - b.x, c.y - b.y});
  ld ans = acosl(x / y) * 180.0 / PI;
  if (ans < 0)
    ans += 360.0;
  return ans;
}
void solve() {
  ll n;
  cin >> n;
  vector<pt> a;
  for (int i = 0; i < n; i++) {
    pt p;
    cin >> p.x >> p.y;
    a.push_back(p);
  }
  convex_hull(a);
  n = a.size();
  if (n < 3) {
    cout << "0\n";
    return;
  }
  ld mn = 360;
  /* cout << a.size() << '\n'; */
  /* for (auto p : a) { */
  /*   cout << p.x << ' ' << p.y << '\n'; */
  /* } */
  for (int i = 0; i < n; i++) {
    pt p1 = a[i];
    pt p2 = a[(i + 1) % n];
    pt p3 = a[(i + 2) % n];
    ld ang = angle(p1, p2, p3);
    /* cout << ang << '\n'; */
    /* cout << p1.x << ' ' << p1.y << ' ' << p2.x << ' ' << p2.y << ' ' << p3.x
     */
    /*      << ' ' << p3.y << '\n'; */
    mn = min(mn, ang);
  }
  cout << mn << '\n';
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(16);
  int t, tt = 1;
  cin >> t;
  while (t--) {
    cout << "Case " << tt++ << ": ";
    solve();
  }
#ifdef ONPC
  cerr << endl
       << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif
}
