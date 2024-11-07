#include <bits/stdc++.h>
#include <vector>
using namespace std;
typedef long long ll;
typedef long double ld;

#define sz(a) ((int)((a).size()))

void solve() {
  ll n;
  cin >> n;
  vector<ll> a(n);
  for (ll i = 0; i < n; i++) {
    cin >> a[i];
  }
  ll ans = 0;
  for (ll i = 1; i < n; i++) {
    if (a[i] < a[i - 1]) {
      ans += a[i - 1] - a[i];
      a[i] = a[i - 1];
    }
  }
  cout << ans << '\n';
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();
}
