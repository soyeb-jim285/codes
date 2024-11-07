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
void solve() {
  pt a, b, c, d;
  cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y;
  d.x = c.x + a.x - b.x;
  d.y = c.y + a.y - b.y;
  cout << d.x << " " << d.y << " "
       << abs(a.x * b.y + b.x * c.y + c.x * d.y + d.x * a.y - b.x * a.y -
              c.x * b.y - d.x * c.y - a.x * d.y) /
              2
       << '\n';
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
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
