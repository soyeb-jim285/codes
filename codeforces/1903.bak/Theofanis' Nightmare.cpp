#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
typedef long double ld;
void solve() {
  ll n;
  cin >> n;
  vector<ll> vc(n);
  for (int i = 0; i < n; i++) {
    cin >> vc[i];
  }
  vector<ll> a;
  ll pos = 0, neg = 0;
  reverse(vc.begin(), vc.end());
  for (int i = 0; i < n; i++) {
    if (vc[i] < 0) {
      if (neg - pos - vc[i] > 0 && i != n - 1) {
        vc[i + 1] += vc[i];
      } else {
        neg -= vc[i];
        a.push_back(vc[i]);
      }
    } else {
      pos += vc[i];
      a.push_back(vc[i]);
    }
  }
  reverse(a.begin(), a.end());
  ll ans = 0;
  for (int i = 0; i < a.size(); i++) {
    ans += (i + 1) * a[i];
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
  return 0;
}
