#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
void solve() {
  ll n;
  cin >> n;
  vector<ll> a(n);
  map<ll, ll> mp;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    mp[a[i]] = i;
  }
  ll q;
  cin >> q;
  while (q--) {
    ll l, r;
    cin >> l >> r;
    if (mp[l] < mp[r])
      cout << l << endl;
    else
      cout << r << endl;
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();
#ifdef ONPC
  cerr << endl
       << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif
}
