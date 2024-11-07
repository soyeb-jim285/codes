#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
void solve() {
  ll deg;
  cin >> deg;
  ll x, y;
  cin >> x >> y;
  ld new_x = 1.0 * x * cos(deg * M_PI / 180) - 1.0 * y * sin(deg * M_PI / 180);
  ld new_y = 1.0 * x * sin(deg * M_PI / 180) + 1.0 * y * cos(deg * M_PI / 180);
  cout << new_x << " " << new_y << endl;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(10);
  solve();
#ifdef ONPC
  cerr << endl
       << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif
}
