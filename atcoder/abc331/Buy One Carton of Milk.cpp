#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
void solve() {
  ll n, a, b, c;
  cin >> n >> a >> b >> c;
  ld aa = a / 6;
  ld bb = b / 8;
  ld cc = c / 12;
  cout << aa << bb << cc << "\n";
  if (aa < bb && aa < cc) {
    cout << ceil(1.0 * n / 6) * a << "\n";
  } else if (bb < cc) {
    ll cost = b * (ll)(n / 8);
    ll rem = n % 8;
    ll remcost = min({ceil(1.0 * rem / 6) * a, ceil(1.0 * rem / 8) * b,
                      ceil(1.0 * rem / 12) * c});
    cout << cost + remcost << "\n";
  } else {
    ll cost = c * (ll)(n / 12);
    cout << cost << "\n";
    ll rem = n % 12;
    cout << ceil(1.0 * rem / 6) * a << "\n";
    cout << ceil(1.0 * rem / 8) * b << "\n";
    cout << ceil(1.0 * rem / 12) * c << "\n";
    ll remcost = min({ceil(1.0 * rem / 6) * a, ceil(1.0 * rem / 8) * b,
                      ceil(1.0 * rem / 12) * c});
    cout << cost + remcost << "\n";
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();
  return 0;
}
