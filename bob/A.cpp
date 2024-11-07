#include <bits/stdc++.h>
#include <cmath>
using namespace std;

#define sz(a) ((int)((a).size()))

typedef long long ll;
typedef long double ld;
#define x real()
#define y imag()

// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
typedef complex<ld> point;
ld pi = 3.141592653589793L;
void solve() {
  int l;
  cin >> l;
  ld r = l / 2.0;
  int x1, y1, x2, y2, x3, y3;
  cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
  point a(x1, y1), b(x2, y2), c(x3, y3);
  if (a == b || a == c || b == c) {
    cout << "0\n";
    return;
  }
  ld triangle_area = abs(imag((a - b) * conj(c - b))) / 2;
  ld s = (abs(a - b) + abs(b - c) + abs(c - a)) / 2;
  ld inradius = triangle_area / s;
  if (inradius < r) {
    cout << 0 << "\n";
    return;
  }
  ld corner_area = r * r * s / (inradius);
  cout << setprecision(6) << fixed << triangle_area - corner_area + r * r * pi
       << '\n';
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
