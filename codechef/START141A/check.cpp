#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
void solve() {
  ll ans = 0;
  vector<pair<ll, ll>> vc;
  for (int i = 1; i < 21; i++) {
    for (int j = i + 1; j < 21; j++) {
      ll d = ceil(1.0 * (18 - i) / (i - j)) + 1;
      if (d <= 6) {
        ans++;
        vc.push_back({i, j});
      }
    }
  }
  cout << ans << "\n";
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
