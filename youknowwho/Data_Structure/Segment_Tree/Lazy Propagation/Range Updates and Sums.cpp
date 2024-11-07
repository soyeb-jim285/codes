#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
const int N = 2e5 + 9;
int a[N];
vector<ll> t(4 * N), t_a(4 * N), t_b(4 * N), lazy_a(4 * N), lazy_b(4 * N);
struct segment_tree {
#define lc (n << 1)
#define rc ((n << 1) | 1)
  inline void push(int n, int b, int e) {
    if (lazy_a[n]) {
      t[n] = (e - b + 1) * lazy_a[n];
      if (b != e) {
        lazy_a[lc] = lazy_a[n];
        lazy_a[rc] = lazy_a[n];
        lazy_b[lc] = 0;
        lazy_b[rc] = 0;
      }
      lazy_a[n] = 0;
    }
    if (lazy_b[n]) {
      t[n] += (e - b + 1) * lazy_b[n];
      if (b != e) {
        lazy_b[lc] += lazy_b[n];
        lazy_b[rc] += lazy_b[n];
      }
      lazy_b[n] = 0;
    }
  }
  inline long long combine(long long a, long long b) { return a + b; }
  inline void pull(int n) { t[n] = t[lc] + t[rc]; }
  void build(int n, int b, int e) {
    lazy_a[n] = lazy_b[n] = 0;
    if (b == e) {
      t[n] = a[b];
      return;
    }
    int mid = (b + e) >> 1;
    build(lc, b, mid);
    build(rc, mid + 1, e);
    pull(n);
  }
  void assign(int n, int b, int e, int i, int j, long long v) {
    push(n, b, e);
    if (j < b || e < i)
      return;
    if (i <= b && e <= j) {
      lazy_a[n] = v;
      lazy_b[n] = 0;
      push(n, b, e);
      return;
    }
    int mid = (b + e) >> 1;
    assign(lc, b, mid, i, j, v);
    assign(rc, mid + 1, e, i, j, v);
    pull(n);
  }
  void increment(int n, int b, int e, int i, int j, long long v) {
    push(n, b, e);
    if (j < b || e < i)
      return;
    if (i <= b && e <= j) {
      lazy_b[n] += v;
      push(n, b, e);
      return;
    }
    int mid = (b + e) >> 1;
    increment(lc, b, mid, i, j, v);
    increment(rc, mid + 1, e, i, j, v);
    pull(n);
  }
  long long query(int n, int b, int e, int i, int j) {
    push(n, b, e);
    if (i > e || b > j)
      return 0; // return null
    if (i <= b && e <= j)
      return t[n];
    int mid = (b + e) >> 1;
    return combine(query(lc, b, mid, i, j), query(rc, mid + 1, e, i, j));
  }
};
void solve() {
  ll n, q;
  cin >> n >> q;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  segment_tree st;
  st.build(1, 0, n - 1);
  while (q--) {
    int type;
    cin >> type;
    if (type == 1) {
      int l, r, val;
      cin >> l >> r >> val;
      // l--, r--;
      st.increment(1, 0, n - 1, l - 1, r - 1, val);

    } else if (type == 2) {
      int l, r, val;
      cin >> l >> r >> val;
      st.assign(1, 0, n - 1, l - 1, r - 1, val);
      // l--, r--;
      // st.point_upd(1, 0, n - 1, l - 1, val);
    } else {
      int l, r;
      cin >> l >> r;
      // l--, r--;
      cout << st.query(1, 0, n - 1, l - 1, r - 1) << '\n';
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
