#include <bits/stdc++.h>
using namespace std;

#define sz(a) ((int)((a).size()))

typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

ll val(ll l, ll r, ll u, vector<ll> &pref) {
  ll n = pref[r] - pref[l - 1];
  ll sum = (pref[r] - pref[l - 1]) * (pref[r] - pref[l - 1] - 1) / 2;
  return n * u - sum;
}
void solve() {
  ll n;
  cin >> n;
  vector<ll> a(n), pref(n + 1);
  for (ll i = 0; i < n; i++) {
    cin >> a[i];
    pref[i + 1] = pref[i] + a[i];
  }
  ll q;
  cin >> q;
  while (q--) {
    ll l, u;
    cin >> l >> u;
    ll nwl = l, r = n;
    while (r - l > 4) {
      ll mid1 = l + (r - l) / 3;
      ll mid2 = r - (r - l) / 3;
      if (val(nwl, mid1, u, pref) > val(nwl, mid2, u, pref)) {
        r = mid2;
      } else {
        l = mid1;
      }
    }
    ll mx = -1e9, ans;
    for (ll i = max({1LL, l - 3, nwl}); i <= min(n, r + 3); i++) {
      if (val(nwl, i, u, pref) > mx) {
        mx = val(nwl, i, u, pref);
        ans = i;
      }
    }
    cout << ans << " ";
  }
  cout << "\n";
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
