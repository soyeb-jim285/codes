#include <iostream>
#include <system_error>
#include <vector>
using namespace std;
typedef long long ll;
typedef long double ld;
bool fn(vector<pair<ll, ll>> &vc, ll k) {
  ll lw = 0, hg = 0;
  for (int i = 0; i < vc.size(); i++) {
    lw -= k;
    hg += k;
    if (abs(lw - vc[i].first) + abs(hg - vc[i].second) <=
        abs(hg - lw + vc[i].second - vc[i].first)) {
      hg = min(hg, vc[i].second);
      lw = max(lw, vc[i].first);
    } else
      return 0;
  }
  return 1;
}
void solve() {
  ll n;
  cin >> n;
  vector<pair<ll, ll>> vc(n);
  for (int i = 0; i < n; i++) {
    cin >> vc[i].first >> vc[i].second;
  }
  ll low = 0, high = 1e9;
  while (high > low) {
    ll mid = (high + low) >> 1;
    if (fn(vc, mid))
      high = mid - 1;
    else
      low = mid + 1;
  }
  for (ll i = max(0LL, low - 5); i < min((ll)1e12, low + 5); i++) {
    if (fn(vc, i)) {
      cout << i << "\n";
      return;
    }
  }
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
