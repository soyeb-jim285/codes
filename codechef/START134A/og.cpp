#include <bits/stdc++.h>
using namespace std;

#define sz(a) ((int)((a).size()))

typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
ll digitsum(ll n) {
  ll res = 0;
  while (n) {
    res += n % 10;
    n /= 10;
  }
  return res;
}
void solve() {
  ll n;
  cin >> n;
  ll ans = n / 9;
  ans *= 9 * 5;
  ll rem = n % 9;
  ans += rem * (rem + 1) / 2;
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
