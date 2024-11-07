#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
void solve() {
  ll n;
  cin >> n;
  vector<pair<ll, ll>> vc(n);
  for (int i = 0; i < n; i++) {
    cin >> vc[i].first >> vc[i].second;
  }
  ll mn = 1e10;
  vector<pair<ll, ll>> ans;
  for (int i = 0; i < 1000; i++) {
    for (int j = 0; j < 1000; j++) {
      ll mx = -1;
      for (int k = 0; k < n; k++) {
        mx = max(mx, abs(i - vc[k].first) + abs(j - vc[k].second));
      }
      if (mx <= mn) {
        if (mx < mn) {
          ans.clear();
        }
        mn = mx;
        ans.push_back({i, j});
      }
    }
  }
  cout << mn << " " << ans[0].first << " " << ans[0].second << "\n";
  for (auto ic : ans) {
    cout << ic.first << " " << ic.second << "\n";
  }
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
