#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

#define sz(a) ((int)((a).size()))

typedef long long ll;
typedef long double ld;

void solve() {
  ll n, k;
  cin >> n >> k;
  vector<ll> vc(n), vc2(n), pre(n);
  vector<vector<ll>> v(n, vector<ll>(3));
  for (int i = 0; i < n; i++) {
    cin >> vc[i];
    if (i == 0)
      pre[i] = vc[i];
    else
      pre[i] = pre[i - 1] + vc[i];
  }
  ll mx = 0, ans = 0;
  for (int i = 0; i < n; i++) {
    cin >> vc2[i];
    mx = max(mx, vc2[i]);
    if (i < k) {
      ll tmp = pre[i];
      ll kk = k - i - 1;
      ans = max(ans, tmp + kk * mx);
    }
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
