#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
const int N = 1e5 + 9;
int a[N];
struct segment_tree {
#define lc (n << 1)
#define rc ((n << 1) | 1)
  long long t[4 * N];
  int indx[4 * N];
  bool lazy[4 * N];
  segment_tree() {
    memset(t, 0, sizeof t);
    memset(lazy, 0, sizeof lazy);
    memset(indx, -1, sizeof indx);
  }
  inline void push(int n, int b, int e) {
    if (lazy[n] == 0)
      return;
    t[n] = (e - b + 1) - t[n];
    if (b != e) {
      lazy[lc] = lazy[lc] ^ lazy[n];
      lazy[rc] = lazy[rc] ^ lazy[n];
    }
    lazy[n] = 0;
  }
  inline long long combine(long long a, long long b) { return a + b; }
  inline void pull(int n) { t[n] = t[lc] + t[rc]; }
  void build(int n, int b, int e) {
    lazy[n] = 0;
    if (b == e) {
      t[n] = a[b];
      indx[n] = b;
      return;
    }
    int mid = (b + e) >> 1;
    build(lc, b, mid);
    build(rc, mid + 1, e);
    pull(n);
  }
  void upd(int n, int b, int e, int i, int j) {
    push(n, b, e);
    if (j < b || e < i)
      return;
    if (i <= b && e <= j) {
      // cout << "booo\n";
      lazy[n] = 1; // set lazy
      push(n, b, e);
      return;
    }
    int mid = (b + e) >> 1;
    upd(lc, b, mid, i, j);
    upd(rc, mid + 1, e, i, j);
    pull(n);
  }
  long long query(int n, int k, int b, int e, int i, int j) {
    // cout << n << " " << k << " " << b << " " << e << " " << i << " " << j <<
    // " "
    //      << endl;

    push(n, b, e);
    if (t[n] == k && b == e) {
      // cout << "bingo" << n << " " << k << endl;
      return b + 1;
    }
    ll mid = (b + e) >> 1;
    push(lc, b, mid);
    push(rc, mid + 1, e);
    if (t[lc] >= k)
      return query(lc, k, b, mid, i, j);
    else if (t[rc] >= k - t[lc])
      return query(rc, k - t[lc], mid + 1, e, i, j);
    else
      return -1;
  }
};
void solve() {
  ll n, m;
  cin >> n >> m;
  segment_tree st;
  st.build(1, 0, n - 1);
  for (int i = 0; i < m; i++) {
    int type;
    cin >> type;
    if (type == 1) {
      int l, r;
      cin >> l >> r;
      st.upd(1, 0, n - 1, l - 1, r - 1);
    } else {
      int k;
      cin >> k;
      cout << st.query(1, k, 0, n - 1, 0, n - 1) << '\n';
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
// 0110001000
