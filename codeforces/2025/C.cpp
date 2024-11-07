#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

#define sz(a) ((int)((a).size()))

typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
void solve() {
  ll n, k;
  cin >> n >> k;
  map<ll, ll> mp;
  for (int i = 0; i < n; i++) {
    ll x;
    cin >> x;
    mp[x]++;
  }
  vector<ll> a, b;
  for (auto ic : mp) {
    b.push_back(ic.first);
    a.push_back(ic.second);
  }
  vector<ll> tmp, tmp2, pref;
  pref.push_back(0);
  ll mx = 0;
  for (int i = 0; i < sz(a); i++) {
    tmp.push_back(b[i]);
    tmp2.push_back(a[i]);
    pref.push_back(pref.back() + a[i]);
    if (mp.find(b[i] + 1) == mp.end()) {
      for (int j = 0; j < sz(tmp); j++) {
        // cout << "tmp[j] = " << tmp[j] << " " << pref[j] << '\n';
        auto it =
            upper_bound(tmp.begin(), tmp.end(), tmp[j] + k - 1) - tmp.begin();
        // cout << "it = " << it << " " << pref[it] << '\n';
        mx = max(mx, pref[it] - pref[j]);
      }
      // cout << "---\n";
      pref.clear();
      pref.push_back(0);
      tmp.clear();
      tmp2.clear();
    }
  }
  cout << mx << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
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
