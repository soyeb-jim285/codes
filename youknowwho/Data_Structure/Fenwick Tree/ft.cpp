#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define sz(a) ((int)((a).size()))
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
struct FT {
  vector<ll> s;
  FT(int n) : s(n) {}
  void update(int pos, ll dif) { // a[pos] += dif
    for (; pos < sz(s); pos |= pos + 1)
      s[pos] += dif;
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
  ll n, q;
  cin >> n >> q;
  vector<ll> a(n);
  for (ll &x : a)
    cin >> x;
  FT ft(n);
  for (ll i = 0; i < n; i++)
    ft.update(i, a[i]);
  while (q--) {
    ll x;
    cin >> x;
    if (x == 1) {
      ll l, v;
      cin >> l >> v;
      ft.update(l, v);
    } else {
      ll l, r;
      cin >> l >> r;
      cout << ft.query(l, r) << endl;
    }
  }
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
