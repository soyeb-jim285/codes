#include <algorithm>
#include <bits/stdc++.h>
#include <system_error>
#include <vector>
using namespace std;
typedef long long ll;
typedef long double ld;
void solve() {
  ll n;
  cin >> n;
  set<ll> s;
  vector<ll> vc(n);
  for (int i = 0; i < n; i++) {
    ll x;
    cin >> x;
    vc[i] = x;
    s.insert(x);
  }
  sort(vc.begin(), vc.end());
  ll g = -1;
  for (int i = 0; i < n - 1; i++) {
    if (g == -1) {
      g = vc[i + 1] - vc[i];
      continue;
    }
    g = __gcd(g, vc[i + 1] - vc[i]);
  }
  ll ans = 0;
  for (int i = 0; i < n; i++) {
    ans += (vc[n - 1] - vc[i]) / g;
  }
  for (int i = 0; i < n; i++) {
    if (!s.count(vc[n - 1] - g * i)) {
      ans += i;
      cout << ans << "\n";
      return;
    }
  }
  ans += n;
  cout << ans << "\n";
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
