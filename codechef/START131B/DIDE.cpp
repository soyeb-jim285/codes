#include <bits/stdc++.h>
using namespace std;

#define sz(a) ((int)((a).size()))

typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
void solve() {
  ll n, k;
  cin >> n >> k;
  vector<ll> a(n);
  for (ll &x : a)
    cin >> x;
  ll ans = 0;
  sort(a.begin(), a.end());
  for (int i = 0; i < k; i++) {
    a[i] = max(a[i], 7 - a[i]);
  }
  for (int i = 0; i < n; i++) {
    ans += a[i];
  }
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
