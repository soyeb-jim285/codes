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
  int n, q;
  cin >> n >> q;
  vector<int> a(n), vals;
  for (int &x : a)
    cin >> x;
  vals = a;
  vector<array<int, 3>> queries;
  for (int i = 0; i < q; i++) {
    char ch;
    int a, b;
    cin >> ch >> a >> b;
    queries.push_back({ch == '!', a, b});
    if (ch == '!')
      vals.push_back(b);
  }
  sort(vals.begin(), vals.end());
  vals.erase(unique(vals.begin(), vals.end()), vals.end());
  BIT<int> bit(vals.size());
  for (int i = 0; i < n; i++) {
    int x = upper_bound(vals.begin(), vals.end(), a[i]) - vals.begin();
    bit.upd(x, 1);
  }
  for (int i = 0; i < q; i++) {
    if (queries[i][0] == 1) {
      int x = upper_bound(vals.begin(), vals.end(), a[queries[i][1] - 1]) -
              vals.begin();
      bit.upd(x, -1);
      a[queries[i][1] - 1] = queries[i][2];
      x = upper_bound(vals.begin(), vals.end(), a[queries[i][1] - 1]) -
          vals.begin();
      bit.upd(x, 1);
    } else {
      int l = upper_bound(vals.begin(), vals.end(), queries[i][1] - 1) -
              vals.begin();
      int r =
          upper_bound(vals.begin(), vals.end(), queries[i][2]) - vals.begin();
      cout << bit.query(l + 1, r) << "\n";
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
