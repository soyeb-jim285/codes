#include <bits/stdc++.h>
using namespace std;

#define sz(a) ((int)((a).size()))

typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
void solve() {
  ll n;
  cin >> n;
  map<ll, ll> mp;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    ll x;
    cin >> x;
    mp[x]++;
  }
  ll ans = 0, mx = 0;
  for (auto ic : mp) {
    if (ic.second > mx) {
      mx = ic.second;
      ans = ic.first;
    }
  }
  cout << ans << '\n';
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--)
    solve();
#ifdef ONPC
  cerr << endl
       << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif
}
