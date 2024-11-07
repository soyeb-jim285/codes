#include <bits/stdc++.h>
using namespace std;

#define sz(a) ((int)((a).size()))

typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
struct pt {
  ll x, y;
};
ld angle(pt a, pt b, pt c) {
  ld x1 = b.x - a.x, y1 = b.y - a.y;
  ld x2 = c.x - a.x, y2 = c.y - a.y;
  return atan2(x1 * y2 - x2 * y1, x1 * x2 + y1 * y2);
}
void solve() {
  pt a, b, c;
  cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y;
  if ((a.x - b.x) * (a.y - c.y) == (a.y - b.y) * (a.x - c.x)) {
    cout << "TOUCH\n";
  } else {
    if (angle(a, b, c) < 0)
      cout << "RIGHT\n";
    else
      cout << "LEFT\n";
  }
}
int main() {
  ios::sync_with_stdio(false);
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
