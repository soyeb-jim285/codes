#include <bits/stdc++.h>
using namespace std;

#define sz(a) ((int)((a).size()))

typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
struct pt {
  ll x, y;
};
void solve() {
  ll n;
  cin >> n;
  vector<pt> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i].x >> a[i].y;
  }
  ll mx = 1;
  for (int i = 0; i < n; i++) {
    map<pair<ll, ll>, int> m;
    for (int j = i + 1; j < n; j++) {
      ll up = a[j].y - a[i].y;
      ll down = a[j].x - a[i].x;
      ll g = __gcd(up, down);
      up /= g;
      down /= g;
      m[{up, down}]++;
    }
    for (auto ic : m) {
      mx = max(mx, ic.second + 1LL);
    }
  }
  cout << mx << '\n';
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t, tt = 1;
  cin >> t;
  while (t--) {
    cout << "Case " << tt++ << ": ";
    solve();
  }
#ifdef ONPC
  cerr << endl
       << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif
}
