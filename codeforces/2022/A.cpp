#include <bits/stdc++.h>
using namespace std;

#define sz(a) ((int)((a).size()))

typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
void solve() {
  ll n, r;
  cin >> n >> r;
  ll ans = 0, cnt = 0;
  for (int i = 0; i < n; i++) {
    ll x;
    cin >> x;
    ll d = x / 2;
    ans += 2 * d;
    cnt += x % 2;
  }
  r = r - ans / 2;
  ans += min(cnt, r);
  cnt -= min(cnt, r);
  if (cnt) {
    ans -= cnt;
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
