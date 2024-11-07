#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
ll const mod = 998244353;
void solve() {
  ll n, m;
  cin >> n >> m;
  vector<ll> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  // cout << "n = " << n << endl;
  while (m--) {
    int type;
    cin >> type;
    // cout << "type = " << type << endl;
    if (type == 0) {
      int l, r, b, c;
      cin >> l >> r >> b >> c;
      // cout << "l = " << l << " r = " << r << " b = " << b << " c = " << c
      // << endl;
      r--;
      for (int i = l; i <= r; i++) {
        a[i] = ((a[i] * b) % mod + c) % mod;
      }
    } else {
      ll l, r;
      cin >> l >> r;
      // cout << "l = " << l << " r = " << r << endl;
      ll sum = 0;
      for (int i = l; i < r; i++) {
        sum = (sum + a[i]) % mod;
      }
      cout << sum << '\n';
    }
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
