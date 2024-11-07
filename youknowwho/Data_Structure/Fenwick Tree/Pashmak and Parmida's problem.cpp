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
  int n;
  cin >> n;
  int a[n];
  map<int, int> bck, frnt;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    bck[a[i]]++;
  }
  vector<int> left(n), right(n);
  for (int i = 0; i < n; i++) {
    frnt[a[i]]++;
    left[i] = frnt[a[i]];
    right[i] = bck[a[i]];
    bck[a[i]]--;
  }
  ll ans = 0;
  BIT<int> bit(n + 1);
  for (int i = n - 1; i >= 0; i--) {
    ans += bit.query(left[i] - 1);
    bit.upd(right[i], 1);
  }
  cout << ans << '\n';
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
