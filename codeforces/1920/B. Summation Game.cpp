#include <bits/stdc++.h>
using namespace std;

#define sz(a) ((int)((a).size()))

typedef long long ll;
typedef long double ld;
void solve() {
  ll n, k, x;
  cin >> n >> k >> x;
  vector<ll> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a.begin(), a.end());
  vector<ll> pre_sum(n + 1);
  for (int i = 0; i < n; i++) {
    pre_sum[i + 1] = pre_sum[i] + a[i];
  }
  ll ans = pre_sum[n] - 2 * (pre_sum[n] - pre_sum[max(0LL, n - x)]);
  ll lst = 0;
  for (int i = 0; i < k; i++) {
    lst += a[n - 1 - i];
    ll kp =
        pre_sum[n] - 2 * (pre_sum[n] - pre_sum[max(0LL, n - x - i - 1)]) + lst;
    ans = max(ans, kp);
  }
  cout << ans << endl;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--)
    solve();
}
