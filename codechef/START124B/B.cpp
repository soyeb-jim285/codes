#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve() {
  ll n;
  cin >> n;
  vector<ll> vc(n);
  for (int i = 0; i < n; i++) {
    cin >> vc[i];
  }
  sort(vc.begin(), vc.end());
  reverse(vc.begin(), vc.end());
  ll mx = 0;
  for (int i = 0; i < n; i++) {
    mx = max(mx, vc[i] * (i + 1LL));
  }
  cout << mx << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--)
    solve();
}
