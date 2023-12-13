#include <bits/stdc++.h>
using namespace std;

#define sz(a) ((int)((a).size()))

typedef long long ll;
typedef long double ld;
void solve() {
  ll n;
  cin >> n;
  vector<ll> vc(n);
  for (int i = 0; i < n; i++) {
    cin >> vc[i];
  }
  map<ll, ll> mp;
  for (int i = 0; i < n; i++) {
    ll x;
    cin >> x;
    mp[vc[i]] = max(mp[vc[i]], x);
  }
  ll ans = 0;
  for (auto ic : mp) {
    ans += ic.second;
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
