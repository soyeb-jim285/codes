#include <bits/stdc++.h>
using namespace std;

#define sz(a) ((int)((a).size()))

typedef long long ll;
typedef long double ld;
void solve() {
  ll n;
  cin >> n;
  vector<ll> a(4), tmp;
  a[2] = 1e18;
  for (int i = 0; i < n; i++) {
    ll x, y;
    cin >> x >> y;
    if (x == 1) {
      a[x] = max(a[x], y);
    } else if (x == 2) {
      a[x] = min(a[x], y);
    } else {
      tmp.push_back(y);
    }
  }
  sort(tmp.begin(), tmp.end());
  auto ic = upper_bound(tmp.begin(), tmp.end(), a[2]) - tmp.begin();
  auto dc = lower_bound(tmp.begin(), tmp.end(), a[1]) - tmp.begin();
  /* cout << a[1] << ' ' << a[2] << ' ' << ic << ' ' << dc << endl; */
  cout << max(a[2] - a[1] + 1 - ic + dc, 0LL) << endl;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--)
    solve();
}
