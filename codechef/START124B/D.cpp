#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve() {
  ll l, r;
  cin >> l >> r;
  ll n = r - l + 1;
  vector<ll> ans(n);
  ans[n - 1] = r;
  if (n % 2) {
    if (l % 2 == 0) {
      cout << "-1\n";
      return;
    }
  }
  for (int i = 0; i < n - 1; i += 2) {
    ans[i] = l + i + 1;
    ans[i + 1] = l + i;
  }
  if (n % 2) {
    swap(ans[n - 1], ans[n - 3]);
  }
  for (int i = 0; i < n; i++) {
    cout << ans[i] << " ";
  }
  cout << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--)
    solve();
}
