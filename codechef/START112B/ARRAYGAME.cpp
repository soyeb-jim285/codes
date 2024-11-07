#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

#define sz(a) ((int)((a).size()))

ll s;

void solve() {
  ll n;
  cin >> n;
  vector<ll> vc(n);
  for (ll i = 0; i < n; i++) {
    cin >> vc[i];
  }
  sort(vc.begin(), vc.end());
  vector<ll> prefix_sum(n + 1);
  for (int i = 0; i < n; i++) {
    prefix_sum[i + 1] = prefix_sum[i] + vc[i];
  }
  if (s == 0) {
    if (n % 2) {
      cout << prefix_sum[n / 2 + 1] << '\n';
    } else {
      cout << prefix_sum[n / 2 + 1] - vc[0] << '\n';
    }
  } else {
    ll ans = 0;
    for (int i = 1; i <= ceil(1.0 * n / 2); i++) {
      ll kp = prefix_sum[n - i + 1] - prefix_sum[n - i + 1 - i];
      ans = max(ans, kp);
    }
    cout << ans << '\n';
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll t;
  cin >> t >> s;
  while (t--)
    solve();
}
