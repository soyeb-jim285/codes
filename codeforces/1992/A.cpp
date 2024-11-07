#include <bits/stdc++.h>
using namespace std;

#define sz(a) ((int)((a).size()))

typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
void solve() {
  ll a, b, c, mx = 0;
  cin >> a >> b >> c;
  for (int i = 0; i <= 5; i++) {
    for (int j = 0; j <= 5; j++) {
      for (int k = 0; k <= 5; k++) {
        if (i + j + k <= 5) {
          ll ans = (a + i) * (b + j) * (c + k);
          mx = max(mx, ans);
        }
      }
    }
  }
  cout << mx << "\n";
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
