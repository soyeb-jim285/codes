#include <bits/stdc++.h>
using namespace std;

#define sz(a) ((int)((a).size()))

typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
void solve() {
  ll n, t, h;
  cin >> n >> t >> h;
  ll ans = 0;
  if (n > h) {
    ans += (n - h + 1) * n;
    // cout << ans << "---\n";
    for (ll i = 1; i < h; i++) {
      ans += min(max(((i * t - h) / (t - 1)), 0LL), n);
    }
  } else {
    for (ll i = 1; i <= n; i++) {
      ans += min(max(((i * t - h) / (t - 1)), 0LL), n);
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
