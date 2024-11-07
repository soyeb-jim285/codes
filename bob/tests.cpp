#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
void solve() {
  ll t = 1e6;
  cout << t << "\n";
  ll high = 10;
  while (t--) {
    ll n = rnd() % high;
    int aa = rnd() % 3, bb = rnd() % 3;
    aa = 1, bb = 1;
    ll point_high = 1e2, point_low = -1e2;
    ll x1 = rnd() % (point_high - point_low + 1) + point_low,
       y1 = rnd() % (point_high - point_low + 1) + point_low;
    ll x2 = rnd() % (point_high - point_low + 1) + point_low,
       y2 = rnd() % (point_high - point_low + 1) + point_low;
    cout << x1 << " " << y1 << " " << x2 << " " << y2 << "\n";
    cout << n << "\n";
    // cout << aa << " " << bb << "\n";
    if (aa && n > 0) {
      ll a = rnd() % (point_high - point_low + 1) + point_low,
         b = rnd() % (point_high - point_low + 1) + point_low;
      ll c = -b * y1 - a * x1;
      // cout << c << " c1\n";
      if (abs(c) <= 1e9) {
        n--;
        cout << a << " " << b << " " << c << "\n";
      }
    }
    if (bb && n > 0) {
      ll a = rnd() % (point_high - point_low + 1) + point_low,
         b = rnd() % (point_high - point_low + 1) + point_low;
      ll c = -b * y2 - a * x2;
      // cout << c << " c2\n";
      if (abs(c) <= 1e9) {
        n--;
        cout << a << " " << b << " " << c << "\n";
      }
    }
    for (int i = 0; i < n; i++) {
      ll a = rnd() % (point_high - point_low + 1) + point_low,
         b = rnd() % (point_high - point_low + 1) + point_low,
         c = rnd() % (point_high - point_low + 1) + point_low;
      cout << a << " " << b << " " << c << "\n";
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
