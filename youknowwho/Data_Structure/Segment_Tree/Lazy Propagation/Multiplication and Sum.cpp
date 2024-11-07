#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
ll const mod = 1e9 + 7;
const int N = 1e5 + 9;
int a[N];
ll binpowmod(ll a, ll b, ll m) {
  ll res = 1;
  while (b > 0) {
    if (b & 1) {
      res *= a;
      res = res % m;
    }
    a *= a;
    a = a % m;
    b >>= 1;
  }
  return res;
}
struct segment_tree {
#define lc (n << 1)
#define rc ((n << 1) | 1)
  long long t[4 * N], lazy[4 * N];
  segment_tree() {
    memset(t, 0, sizeof t);
    memset(lazy, 1, sizeof lazy);
  }
  inline void push(int n, int b, int e) {
    if (lazy[n] == 1)
      return;
    t[n] = (t[n] * lazy[n]) % mod;
    if (b != e) {
      lazy[lc] = (lazy[lc] * lazy[n]) % mod;
      lazy[rc] = (lazy[rc] * lazy[n]) % mod;
    }
    lazy[n] = 1;
  }
  inline long long combine(long long a, long long b) { return (a + b) % mod; }
  inline void pull(int n) { t[n] = (t[lc] + t[rc]) % mod; }
  void build(int n, int b, int e) {
    lazy[n] = 1;
    if (b == e) {
      t[n] = a[b];
      return;
    }
    int mid = (b + e) >> 1;
    build(lc, b, mid);
    build(rc, mid + 1, e);
    pull(n);
  }
  void upd(int n, int b, int e, int i, int j, long long v) {
    push(n, b, e);
    if (j < b || e < i)
      return;
    if (i <= b && e <= j) {
      lazy[n] = v; // set lazy
      push(n, b, e);
      return;
    }
    int mid = (b + e) >> 1;
    upd(lc, b, mid, i, j, v);
    upd(rc, mid + 1, e, i, j, v);
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
  ll n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    a[i] = 1;
  }
  segment_tree st;
  st.build(1, 1, n);
  // for (int i = 1; i < 10; i++) {
  //   cout << st.t[i] << ' ';
  // }
  // cout << '\n';
  // for (int i = 1; i < 10; i++) {
  //   cout << st.lazy[i] << ' ';
  // }
  // cout << '\n';
  // cout << "----------------\n";

  for (int i = 0; i < m; i++) {
    ll x;
    cin >> x;
    ll l, r;
    cin >> l >> r;
    l++;
    if (x == 1) {
      ll val;
      cin >> val;
      st.upd(1, 1, n, l, r, val);
    } else {
      cout << st.query(1, 1, n, l, r) << '\n';
    }
    // for (int i = 1; i < 10; i++) {
    //   cout << st.t[i] << ' ';
    // }
    // cout << '\n';
    // for (int i = 1; i < 10; i++) {
    //   cout << st.lazy[i] << ' ';
    // }
    // cout << '\n';
    // cout << "----------------\n";
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
