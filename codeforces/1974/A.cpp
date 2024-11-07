#include <bits/stdc++.h>
using namespace std;

#define sz(a) ((int)((a).size()))

typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
void solve() {
  ll x, y, ans = 0;
  cin >> x >> y;
  while (y > 0) {
    if (y > 1) {
      y -= 2;
      x -= 7;
      ans++;
    } else {
      y--;
      ans++;
      x -= 11;
    }
  }
  if (x > 0) {
    ans += ceil(1.0 * x / 15);
  }
  cout << ans << '\n';
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
