#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
const int N = 2e5 + 9;
const int mod = 998244353;
int a[N], bb[N];
vector<ll> t(4 * N), lazy_a(4 * N), lazy_b(4 * N), t_a(4 * N), t_b(4 * N);
struct segment_tree {
#define lc (n << 1)
#define rc ((n << 1) | 1)
  inline void push_a(int n, int b, int e) {
    if (lazy_a[n] == 0)
      return;
    t_a[n] = (t_a[n] + lazy_a[n] * (e - b + 1)) % mod;
    t[n] = (t[n] + t_b[n] * lazy_a[n]) % mod;
    if (b != e) {
      lazy_a[lc] = (lazy_a[lc] + lazy_a[n]) % mod;
      lazy_a[rc] = (lazy_a[rc] + lazy_a[n]) % mod;
    }
    lazy_a[n] = 0;
  }
  inline void push_b(int n, int b, int e) {
    if (lazy_b[n] == 0)
      return;
    t_b[n] = (t_b[n] + lazy_b[n] * (e - b + 1)) % mod;
    t[n] = (t[n] + t_a[n] * lazy_b[n]) % mod;
    if (b != e) {
      lazy_b[lc] = (lazy_b[lc] + lazy_b[n]) % mod;
      lazy_b[rc] = (lazy_b[rc] + lazy_b[n]) % mod;
    }
    lazy_b[n] = 0;
  }
  inline long long combine(long long a, long long b) { return (a + b) % mod; }
  inline void pull(int n) {
    t[n] = (t[lc] + t[rc]) % mod;
    t_a[n] = (t_a[lc] + t_a[rc]) % mod;
    t_b[n] = (t_b[lc] + t_b[rc]) % mod;
  }
  void build(int n, int b, int e) {
    lazy_a[n] = 0;
    lazy_b[n] = 0;
    if (b == e) {
      t_a[n] = a[b];
      t_b[n] = bb[b];
      t[n] = (t_a[n] * t_b[n]) % mod;
      return;
    }
    int mid = (b + e) >> 1;
    build(lc, b, mid);
    build(rc, mid + 1, e);
    pull(n);
  }
  void upd_a(int n, int b, int e, int i, int j, long long v) {
    push_a(n, b, e);
    push_b(n, b, e);
    if (j < b || e < i)
      return;
    if (i <= b && e <= j) {
      lazy_a[n] = v; // set lazy
      push_a(n, b, e);
      return;
    }
    int mid = (b + e) >> 1;
    upd_a(lc, b, mid, i, j, v);
    upd_a(rc, mid + 1, e, i, j, v);
    pull(n);
  }
  void upd_b(int n, int b, int e, int i, int j, long long v) {
    push_a(n, b, e);
    push_b(n, b, e);
    if (j < b || e < i)
      return;
    if (i <= b && e <= j) {
      lazy_b[n] = v; // set lazy
      push_b(n, b, e);
      return;
    }
    int mid = (b + e) >> 1;
    upd_b(lc, b, mid, i, j, v);
    upd_b(rc, mid + 1, e, i, j, v);
    pull(n);
  }
  long long query(int n, int b, int e, int i, int j) {
    push_a(n, b, e);
    push_b(n, b, e);
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
  for (int i = 0; i < n; i++) {
    cin >> bb[i];
  }
  segment_tree st;
  st.build(1, 0, n - 1);
  while (q--) {
    int x;
    cin >> x;
    if (x == 1) {
      int l, r, val;
      cin >> l >> r >> val;
      l--, r--;
      st.upd_a(1, 0, n - 1, l, r, val);
    } else if (x == 2) {
      int l, r, val;
      cin >> l >> r >> val;
      l--, r--;
      st.upd_b(1, 0, n - 1, l, r, val);
    } else {
      int l, r;
      cin >> l >> r;
      l--, r--;
      cout << st.query(1, 0, n - 1, l, r) << '\n';
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
