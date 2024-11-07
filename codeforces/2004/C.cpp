#include <bits/stdc++.h>
using namespace std;

#define sz(a) ((int)((a).size()))

typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
void solve() {
  int n, k;
  cin >> n >> k;
  ll ans = 0;
  vector<ll> a(n);
  for (auto &x : a)
    cin >> x;
  sort(a.begin(), a.end(), greater<ll>());
  for (int i = 0; i < n; i++) {
    if (i % 2) {
      if (k != 0) {
        ll kk = a[i - 1] - a[i];
        if (kk >= k) {
          a[i] += k;
          k = 0;
        } else {
          a[i] += kk;
          k -= kk;
        }
      }
      ans -= a[i];
    } else {
      ans += a[i];
    }
    // cout << ans << " =\n";
  }
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
