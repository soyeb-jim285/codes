#include <bits/stdc++.h>
using namespace std;

#define sz(a) ((int)((a).size()))

typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
void solve() {
  ll n, k, mx = -1, ans = 0;
  cin >> n >> k;
  vector<ll> a(k);
  for (int i = 0; i < k; i++) {
    cin >> a[i];
    mx = max(mx, a[i]);
    ans += 2 * a[i] - 1;
  }
  ans -= 2 * mx - 1;
  cout << ans << "\n";
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
