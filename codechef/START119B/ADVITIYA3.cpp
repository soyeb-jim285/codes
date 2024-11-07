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
  ll mn = 1e18;
  for (int i = 0; i < n; i++) {
    ll x;
    cin >> x;
    if (x >= k) {
      ll bl = x % k;
      if (bl < 0)
        bl += k;
      mn = min(mn, bl);
    }
  }
  if (mn == 1e18) {
    cout << "-1\n";
    return;
  }
  cout << mn << "\n";
}
int main() {
  ios::sync_with_stdio(false);
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
