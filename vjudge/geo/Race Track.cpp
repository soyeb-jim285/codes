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
ld dis(pt a, pt b) {
  return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}
bool between(pt a, pt b, pt c) {
  if (min(a.x, b.x) <= c.x && c.x <= max(a.x, b.x) && min(a.y, b.y) <= c.y &&
      c.y <= max(a.y, b.y)) {
    return true;
  } else {
    return false;
  }
}
ld perp_dis(pt a, pt b, pt c) {
  ld x1 = a.y - b.y, y1 = b.x - a.x, z1 = a.x * b.y - a.y * b.x;
  ld x2 = y1, y2 = -x1, z2 = -(x2 * c.x + y2 * c.y);
  pt intr;
  intr.x = (y1 * z2 - y2 * z1) / (x1 * y2 - x2 * y1);
  intr.y = (x2 * z1 - x1 * z2) / (x1 * y2 - x2 * y1);
  ld ans = dis(intr, c);
  /* cout << a.x << " " << a.y << " " << b.x << " " << b.y << " " << c.x << " "
   */
  /*      << c.y << " " << intr.x << " " << intr.y << " " << ans << '\n'; */
  if (!between(a, b, intr)) {
    return 1e18;
  }
  ans = sqrtl(ans);
  return ans;
}

void solve() {
  ll n;
  ld mn = 1e18;
  cin >> n;
  vector<pt> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i].x >> a[i].y;
  }
  ll m;
  cin >> m;
  vector<pt> b(m);
  for (int i = 0; i < m; i++) {
    cin >> b[i].x >> b[i].y;
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      mn = min(mn, dis(a[i], b[j]));
      mn = min(mn, perp_dis(b[j], b[(j + 1) % m], a[i]));
    }
  }
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      mn = min(mn, perp_dis(a[j], a[(j + 1) % n], b[i]));
    }
  }

  cout << mn * 0.5 << '\n';
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
