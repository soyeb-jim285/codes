#include <bits/stdc++.h>
using namespace std;

#define sz(a) ((int)((a).size()))

typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
void solve() {
  ll n, k, mx = -1e9;
  cin >> n >> k;
  vector<ll> a(n), b;
  for (ll &x : a) {
    cin >> x;
    mx = max(mx, x);
    b.push_back(x % k);
  }
  ll ans = -1e18;
  sort(b.begin(), b.end());
  ans = b.back() - b.front();
  for (int i = 0; i < n; i++) {
    ans = min(ans, b[i] + k - b[i + 1]);
  }
  cout << ans << "\n";
  // cout << ans << "\n";
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
