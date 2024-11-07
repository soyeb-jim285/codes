#include <bits/stdc++.h>
using namespace std;

#define sz(a) ((int)((a).size()))

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
struct FT {
  vector<ll> s;
  FT(int n) : s(n) {}
  void update(int pos, ll dif) { // a[pos] += dif
    for (; pos < sz(s); pos |= pos + 1)
      s[pos] += dif;
  }
  void update(int l, int r, ll dif) { // a[i] += dif for i in [l, r)
    update(l, dif);
    update(r, -dif);
  }
  ll query(int pos) { // sum of values in [0, pos)
    ll res = 0;
    for (; pos > 0; pos &= pos - 1)
      res += s[pos - 1];
    return res;
  }
  ll query(int l, int r) {
    return query(r) - query(l);
  } // sum of values in [l, r)
  int lower_bound(ll sum) { // min pos st sum of [0, pos] >= sum
    // Returns n if no sum is >= sum, or -1 if empty sum is.
    if (sum <= 0)
      return -1;
    int pos = 0;
    for (int pw = 1 << 25; pw; pw >>= 1) {
      if (pos + pw <= sz(s) && s[pos + pw - 1] < sum)
        pos += pw, sum -= s[pos - 1];
    }
    return pos;
  }
};
void solve() {
  int n, q;
  cin >> n >> q;
  vector<ll> a(n);
  FT ft(n);
  BIT<ll> bit(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    ft.update(i, a[i]);
    bit.upd(i + 1, a[i]);
  }
  while (q--) {
    int t;
    cin >> t;
    if (t == 1) {
      int k;
      cin >> k;
      k++;
      ll val = bit.query(k, k);
      cout << val << '\n';
      bit.upd(k, -val);
    } else if (t == 2) {
      int k;
      ll u;
      cin >> k >> u;
      k++;
      bit.upd(k, u);
    } else {
      int l, r;
      cin >> l >> r;
      l++, r++;
      cout << bit.query(l, r) << '\n';
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t, tt = 1;
  cin >> t;
  while (t--) {
    cout << "Case " << tt++ << ":\n";
    solve();
  }
#ifdef ONPC
  cerr << endl
       << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif
}
