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
    if (i < 0)
      return 0;
    if (i >= n)
      return 0;
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
  vector<int> a(n), vals;
  for (int &x : a)
    cin >> x;
  vals = a;
  sort(vals.begin(), vals.end());
  int q;
  cin >> q;
  vector<array<int, 3>> queries;
  vector<pair<int, int>> qq;
  for (int i = 0; i < q; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    a--, b--;
    queries.push_back({a - 1, b, c});
    qq.push_back({a - 1, c});
    qq.push_back({b, c});
  }
  sort(qq.begin(), qq.end());
  map<pair<int, int>, int> mp;
  BIT<int> bit(n + 1);
  int bg = 0;
  for (int i = 0; i < qq.size(); i++) {
    if (qq[i].first >= 0) {
      bg = i;
      break;
    }
  }
  for (int i = 0; i < n; i++) {
    int x = upper_bound(vals.begin(), vals.end(), a[i]) - vals.begin();
    bit.upd(x, 1);
    while (qq[bg].first == i && bg < qq.size()) {
      x = upper_bound(vals.begin(), vals.end(), qq[bg].second) - vals.begin();
      mp[qq[bg]] = i + 1 - bit.query(x);
      bg++;
    }
  }
  for (int i = 0; i < q; i++) {
    cout << mp[{queries[i][1], queries[i][2]}] -
                mp[{queries[i][0], queries[i][2]}]
         << '\n';
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
