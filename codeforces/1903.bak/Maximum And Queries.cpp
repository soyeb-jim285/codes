#include <algorithm>
#include <cstdint>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
typedef long double ld;
ll fn(ll a, ll b) {
  vector<ll> vca(63, 0), vcb(63, 0);
  ll ct = 0;
  while (a) {
    if (a % 2)
      vca[ct] = 1;
    a >>= 1;
    ct++;
  }
  ct = 0;
  while (b) {
    if (b % 2)
      vcb[ct] = 1;
    b >>= 1;
    ct++;
  }
  ll sum = 0;
  for (int i = 0; i < 63; i++) {
    if (vca[i] == 1 && vcb[i] == 1) {
      ll val = (1 << i);
      sum += val;
    }
  }
  return sum;
}
void solve() {
  ll n, q;
  cin >> n >> q;
  vector<ll> pre(63), vc(n);
  vector<vector<ll>> vcpre(n, vector<ll>(63));
  for (int i = 0; i < n; i++) {
    cin >> vc[i];
    for (int j = 63 - 1; j >= 0; j--) {
      if (j == 62) {
        vcpre[i][j] = INT64_MAX - vc[i];
      } else {
        ll val = vc[i] & ((1LL << (j + 1)) - 1);
        vcpre[i][j] = max(0LL, ((ll)(1LL << j) - val));
        cout << vcpre[i][j] << " " << j << " " << (1LL << j) << " "
             << (1 << j) - val << "\n";
      }
    }
    cout << "\n";
  }
  for (int i = 0; i < 63; i++) {
    ll val = 0, tmp = 0;
    for (int j = 0; j < n; j++) {
      val += vcpre[j][i];
      if (val < tmp) {
        val = INT64_MAX;
        break;
      }
      tmp = val;
    }
    pre[i] = val;
  }
  for (auto ic : pre)
    cout << ic << " ";
  cout << "\n";
  while (q--) {
    ll x;
    cin >> x;
    ll ans = 0;
    for (int i = 63 - 1; i >= 0; i--) {
      if (pre[i] <= x) {
        x -= pre[i];
        cout << i << "---\n";
        ans += (1LL << i);
      }
    }
    cout << ans << "\n";
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();
  return 0;
}
