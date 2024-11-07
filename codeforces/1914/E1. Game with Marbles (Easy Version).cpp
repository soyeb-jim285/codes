#include <algorithm>
#include <bits/stdc++.h>
#include <queue>
using namespace std;

#define sz(a) ((int)((a).size()))

typedef long long ll;
typedef long double ld;
void solve() {
  ll n;
  cin >> n;
  vector<ll> a(n), b(n);
  vector<pair<ll, ll>> sum(n);
  ll ans = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> b[i];
    sum[i] = {a[i] + b[i], i};
  }
  sort(sum.begin(), sum.end(), greater<pair<ll, ll>>());
  for (int i = 0; i < n; i++) {
    if (i % 2 == 0) {
      ans += a[sum[i].second] - 1;
    } else {
      ans -= b[sum[i].second] - 1;
    }
  }
  cout << ans << "\n";
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--)
    solve();
}
