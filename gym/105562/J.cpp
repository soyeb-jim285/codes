#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

ll dist(pair<ll, ll> a, pair<ll, ll> b) {
  ll ans = (a.first - b.first) * (a.first - b.first) +
           (a.second - b.second) * (a.second - b.second);
  return ans;
}

void solve() {
  ll n;
  cin >> n;
  vector<pair<ll, ll>> cords(n);
  vector<ll> h(n);
  for (int i = 0; i < n; i++) {
    cin >> cords[i].first >> cords[i].second >> h[i];
  }
  for (int i = 0; i < n; i++) {
    ll mn = h[i];
    for (int j = 0; j < n; j++) {
      if (i == j)
        continue;
      if (h[j] > h[i]) {
        ll d = dist(cords[i], cords[j]);
        d = sqrt(d);
        mn = min(mn, d);
      }
    }
    cout << mn << endl;
  }
}
int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int t = 1;
  // cin >> t;
  while (t--) {
    solve();
  }
#ifdef ONPC
  cerr << endl
       << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif
}
