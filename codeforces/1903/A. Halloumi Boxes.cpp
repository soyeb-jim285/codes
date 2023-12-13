#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

void solve() {
  ll n, k;
  cin >> n >> k;
  vector<ll> vc(n);
  for (int i = 0; i < n; i++) {
    cin >> vc[i];
  }
  if (k == 1) {
    if (is_sorted(vc.begin(), vc.end())) {
      cout << "YES\n";
    } else
      cout << "NO\n";
  } else
    cout << "YES\n";
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll t;
  cin >> t;
  while (t--) {
    solve();
  }
}
