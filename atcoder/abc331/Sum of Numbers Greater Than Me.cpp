#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
typedef long double ld;
void solve() {
  ll n;
  cin >> n;
  vector<pair<ll, ll>> vc(n);
  for (int i = 0; i < n; i++) {
    cin >> vc[i].first;
    vc[i].second = i;
  }
  sort(vc.begin(), vc.end());
  vector<ll> pre(n), ans(n, 0);
  pre[0] = vc[0].first;
  for (int i = 1; i < n; i++) {
    pre[i] = pre[i - 1] + vc[i].first;
  }
  for (int i = n - 1; i >= 0; i--) {
    if (i != n - 1) {
      if (vc[i].first == vc[i + 1].first)
        ans[vc[i].second] = ans[vc[i + 1].second];
      else
        ans[vc[i].second] = pre[n - 1] - pre[i];
    }
  }
  for (auto ic : ans)
    cout << ic << " ";
  cout << "\n";
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();
  return 0;
}
