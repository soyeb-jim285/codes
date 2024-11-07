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
  vector<ll> a(n), b(n);
  vector<bool> ba(n), bb(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> b[i];
  }
  for (int i = 0; i < n; i++) {
    if (a[i] < b[i]) {
      ba[i] = true;
    } else {
      bb[i] = true;
    }
  }
  // for (auto ic : ba) {
  //   cout << ic << ' ';
  // }
  // cout << endl;
  // for (auto ic : bb) {
  //   cout << ic << ' ';
  // }
  // cout << endl;
  vector<pair<ll, ll>> v;
  ll dif = 0, sum = 0;
  bool one = false, two = false;
  for (int i = 0; i < n; i++) {
    if (ba[i]) {
      if (two) {
        v.push_back({dif, sum});
        sum = 0;
        dif = 0;
        two = false;
      }
      sum += a[i];
      dif += a[i] - b[i];
      one = true;
    } else {
      if (one) {
        v.push_back({dif, sum});
        sum = 0;
        dif = 0;
        one = false;
      }
      sum += b[i];
      dif += b[i] - a[i];
      two = true;
    }
  }
  if (sum) {
    v.push_back({dif, sum});
  }
  // for (auto ic : v) {
  //   cout << ic.first << ' ' << ic.second << endl;
  // }
  sort(v.begin(), v.end());
  ll ans = 0;
  for (int i = 0; i < k; i++) {
    if (i == sz(v)) {
      break;
    }
    ans += v[i].second;
  }
  for (int i = k; i < sz(v); i++) {
    ans += v[i].second;
  }
  cout << ans << '\n';
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
