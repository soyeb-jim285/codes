#include <bits/stdc++.h>
using namespace std;

#define sz(a) ((int)((a).size()))

typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
void solve() {
  ll n;
  cin >> n;
  vector<ll> a(n);
  for (ll &x : a)
    cin >> x;
  ll tmp = a.back();
  ll ans = tmp;
  for (int i = n - 2; i >= 0; i--) {
    if (a[i] <= tmp) {
      ans++;
    } else {
      ans = max(ans + 1, a[i]);
    }
    tmp = a[i];
    // cout << ans << " ";
  }
  // cout << endl;
  cout << ans << endl;
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
/*
 * 2 3 3 4 4 5 6 8
 */
