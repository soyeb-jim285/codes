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
  string s;
  cin >> s;
  ll q;
  cin >> q;
  vector<BIT<int>> bit(26, BIT<int>(s.size() + 1));
  for (int i = 0; i < s.size(); i++)
    bit[s[i] - 'a'].upd(i + 1, 1);
  while (q--) {
    int x;
    cin >> x;
    if (x == 1) {
      int pos;
      char x;
      cin >> pos >> x;
      bit[s[pos - 1] - 'a'].upd(pos, -1);
      bit[x - 'a'].upd(pos, 1);
      s[pos - 1] = x;

    } else {
      int l, r;
      cin >> l >> r;
      ll ans = 0;
      for (int i = 0; i < 26; i++) {
        ll d = bit[i].query(l, r);
        ans += d > 0;
      }
      cout << ans << '\n';
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();
#ifdef ONPC
  cerr << endl
       << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif
}
