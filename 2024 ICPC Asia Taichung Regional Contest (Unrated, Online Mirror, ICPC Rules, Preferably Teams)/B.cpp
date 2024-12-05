#include <bits/stdc++.h>
using namespace std;

#define sz(a) ((int)((a).size()))

typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
bool fn(ll mid, ll tot) {
  ll sum = mid * (mid + 1) / 2;
  return sum <= tot;
}
void solve() {
  ll a, b;
  cin >> a >> b;
  ll tot = a + b;
  ll lo = 0, hi = 1e9, ans = 0;
  while (lo <= hi) {
    ll mid = (lo + hi) / 2;
    if (fn(mid, tot)) {
      ans = mid;
      lo = mid + 1;
    } else {
      hi = mid - 1;
    }
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
