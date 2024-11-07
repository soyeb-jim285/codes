#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
void solve() {
  ll n, p, l, m;
  cin >> n >> p >> l >> m;
  ll tottask = ceil(1.0 * n / 7);
  ll a;
  if (tottask % 2) {
    ll dd = tottask / 2;
    ll sum = 2 * dd * m + l * dd + m + l;
    if (sum <= p) {
      a = dd + 1 + ceil(1.0 * (p - sum) / l);
    } else {
      a = ceil(1.0 * p / (2 * m + l));
    }
  } else {
    ll sum = 2 * tottask * m / 2 + l * tottask / 2;
    // cout << sum << "\n";
    if (sum <= p) {
      a = tottask / 2 + ceil(1.0 * (p - sum) / l);
    } else {
      a = ceil(1.0 * p / (2 * m + l));
    }
  }
  cout << n - a << "\n";
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--)
    solve();
  return 0;
}
