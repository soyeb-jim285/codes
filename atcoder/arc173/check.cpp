#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
bool fn(ll n) {
  ll lst = -1;
  while (n > 0) {
    ll k = n % 10;
    if (k == lst)
      return false;
    n /= 10;
    lst = k;
  }
  return true;
}
void solve() {
  ll n = 1e3, ans = 0;
  for (ll i = 1; i <= n; i++) {
    if (fn(i)) {
      ans++;
      cout << i << ' ' << ans << "\n";
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
