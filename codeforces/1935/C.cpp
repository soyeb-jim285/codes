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
  vector<pair<ll, ll>> a(n);
  for (ll i = 0; i < n; i++) {
    cin >> a[i].second >> a[i].first;
  }
  sort(a.begin(), a.end());
  ll mx = 0, xsum = 0;
  multiset<ll> s;
  for (int i = 0; i < sz(a); i++) {
    s.clear();
    xsum = 0;
    for (int j = i; j < sz(a); j++) {
      ll sum = a[j].first - a[i].first;
      s.insert(a[j].second);
      xsum += a[j].second;
      if (xsum + sum <= k) {
        mx = max(mx, (ll)s.size());
      } else {
        xsum -= *s.rbegin();
        s.erase(s.find(*s.rbegin()));
        mx = max(mx, (ll)s.size());
      }
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
