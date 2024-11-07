#include <bits/stdc++.h>
using namespace std;

#define sz(a) ((int)((a).size()))

typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
void solve() {
  ll n, m;
  cin >> n >> m;
  if (n < m)
    swap(n, m);
  vector<pair<ll, ll>> vc;
  ll ans = 0;
  for (ll i = 1; i <= n; i++) {
    for (ll j = i; j <= n; j += i) {
      ll g = __gcd(i, j);
      if (j * g % (i + j) == 0 && j <= m) {
        // cout << i << " " << j << "\n";
        vc.push_back({i, j});
        ans++;
      }
      if (i != j) {
        if (i * g % (i + j) == 0 && i <= m) {
          vc.push_back({j, i});
          // cout << j << " " << i << "\n";
          ans++;
        }
      }
    }
  }
  sort(vc.begin(), vc.end());
  cout << ans << "\n";
  for (auto [x, y] : vc) {
    cout << x << " " << y << "\n";
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  freopen("ans.txt", "w", stdout);
  int t;
  cin >> t;
  while (t--)
    solve();
#ifdef ONPC
  cerr << endl
       << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif
}
