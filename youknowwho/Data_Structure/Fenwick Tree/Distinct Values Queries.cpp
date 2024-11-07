#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
const int N = 3e5 + 9;

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
    for (; i >= 1; i -= (i & -i))
      ans += t[i];
    return ans;
  }
  void upd(int i, T val) {
    if (i <= 0)
      return;
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
  ll n, q;
  cin >> n >> q;
  vector<ll> a(n);
  for (ll i = 0; i < n; i++)
    cin >> a[i];
  vector<vector<pair<ll, ll>>> queries(n);
  for (ll i = 0; i < q; i++) {
    ll l, r;
    cin >> l >> r;
    l--, r--;
    queries[l].push_back({r, i});
  }
  BIT<ll> bit(n + 1);
  map<ll, ll> last;
  vector<ll> ans(q);
  for (int i = n - 1; i >= 0; i--) {
    if (last.count(a[i]))
      bit.upd(last[a[i]], -1);
    last[a[i]] = i;
    bit.upd(i, 1);
    for (auto [r, id] : queries[i])
      ans[id] = bit.query(r);
  }
  for (ll x : ans)
    cout << x << '\n';
}
int main() {
  // ios_base::sync_with_stdio(false);
  // cin.tie(nullptr);
  solve();
#ifdef ONPC
  cerr << endl
       << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif
}
