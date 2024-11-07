#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
const int N = 3e5 + 9;
vector<ll> vals;
template <class T> struct BIT { // 1-indexed
  int n;
  vector<T> t;
  BIT() {}
  BIT(int _n) {
    n = _n;
    t.assign(n + 1, 0);
  }
  T query(int i) {
    T ans = 0;
    i = upper_bound(vals.begin(), vals.end(), i) - vals.begin();
    for (; i >= 1; i -= (i & -i))
      ans += t[i];
    return ans;
  }
  void upd(int i, T val) {
    if (i <= 0)
      return;
    i = upper_bound(vals.begin(), vals.end(), i) - vals.begin();
    for (; i <= n; i += (i & -i))
      t[i] += val;
  }
  void upd(int l, int r, T val) {
    upd(l, val);
    upd(r + 1, -val);
  }
  T query(int l, int r) { return query(r) - query(l - 1); }
};
void solve() {
  ll n;
  cin >> n;
  vector<ll> a(n);
  vector<pair<ll, ll>> queries;
  for (ll i = 0; i < n; i++) {
    cin >> a[i];
    vals.push_back(i + 1);
    vals.push_back(a[i]);
    queries.push_back({a[i], i + 1});
  }
  sort(vals.begin(), vals.end());
  vals.erase(unique(vals.begin(), vals.end()), vals.end());
  sort(queries.begin(), queries.end());
  ll bg = 0, ans = 0;
  BIT<ll> bit(vals.size() + 1);
  for (int i = 0; i < n; i++) {
    bit.upd(a[i], 1);
    while (i + 1 == queries[bg].first && bg < queries.size()) {

      ll d = i + 1 - bit.query(queries[bg].second - 1);
      if (queries[bg].second <= queries[bg].first)
        d--;
      // cout << queries[bg].first << " " << queries[bg].second << " " << d
      //      << "\n";
      ans += d;
      bg++;
    }
  }
  // cout << ans << "\n";
  for (int i = bg; i < queries.size(); i++) {
    ll d = n - 1 - bit.query(queries[i].second - 1);
    // cout << d << "\n";
    ans += d;
  }
  // for (auto ic : a)
  //   cout << ic << " ";
  // cout << "\n";
  // cout << n << " ";
  cout << ans / 2 << "\n";
}
int main() {
  // ios_base::sync_with_stdio(false);
  // cin.tie(nullptr);
  ll t = 1;
  // cin >> t;
  while (t--)
    solve();
#ifdef ONPC
  cerr << endl
       << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif
}
