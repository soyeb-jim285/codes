#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
void solve() {
  ll n;
  cin >> n;
  vector<pair<ll, ll>> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i].first >> a[i].second;
  }
  ll mx = 0;
  vector<ll> divsa, divsb;
  for (ll i = 1; i * i <= a[0].first; i++) {
    /* cout << i << endl; */
    if (a[0].first % i == 0) {
      divsa.push_back(i);
      if (i * i != a[0].first) {
        divsa.push_back(a[0].first / i);
      }
    }
  }
  for (ll i = 1; i * i <= a[0].second; i++) {
    if (a[0].second % i == 0) {
      divsb.push_back(i);
      if (i * i != a[0].second) {
        divsb.push_back(a[0].second / i);
      }
    }
  }
  for (int i = 0; i < divsa.size(); i++) {
    for (int j = 0; j < divsb.size(); j++) {
      ll x = divsa[i], y = divsb[j];
      bool ok = true;
      for (int k = 0; k < n; k++) {
        if (a[k].first % x == 0 && a[k].second % y == 0) {
          continue;
        } else if (a[k].first % y == 0 && a[k].second % x == 0) {
          continue;
        } else {
          ok = false;
          break;
        }
      }
      if (ok) {
        mx = max(mx, x * y / __gcd(x, y));
      }
    }
  }
  cout << mx << "\n";
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();
#ifdef ONPC
  cerr << endl
       << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif
}
