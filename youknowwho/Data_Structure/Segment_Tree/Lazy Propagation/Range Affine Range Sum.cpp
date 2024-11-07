#include <bits/stdc++.h>
using namespace std;

#define sz(a) ((int)((a).size()))

typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
const ll N = 5e5 + 9, mod = 998244353;
ll a[N];
vector<ll> t(4 * N);
vector<pair<ll, ll>> lazy(4 * N, {1, 0});
struct segment_tree {
#define lc (n << 1)
#define rc ((n << 1) | 1)
  inline void push(int n, int b, int e) {
    // cout << "pushing1\n";
    if (lazy[n].first == 0 && lazy[n].second == 0)
      return;
    // cout << "pushing1\n";
    t[n] = ((t[n] * lazy[n].first) % mod + (e - b + 1) * lazy[n].second) % mod;
    // cout << "pushing1\n";
    if (b != e) {
      lazy[lc].first = (lazy[lc].first * lazy[n].first) % mod;
      lazy[rc].first = (lazy[rc].first * lazy[n].first) % mod;
      lazy[lc].second =
          (lazy[lc].second * lazy[n].first + lazy[n].second) % mod;
      lazy[rc].second =
          (lazy[rc].second * lazy[n].first + lazy[n].second) % mod;
    }
    // cout << "pushing1\n";
    lazy[n].first = 1;
    lazy[n].second = 0;
  }
  inline long long combine(long long a, long long b) { return (a + b) % mod; }
  inline void pull(int n) { t[n] = (t[lc] + t[rc]) % mod; }
  void build(int n, int b, int e) {
    lazy[n] = {1, 0};
    if (b == e) {
      t[n] = a[b];
      return;
    }
    int mid = (b + e) >> 1;
    build(lc, b, mid);
    build(rc, mid + 1, e);
    pull(n);
  }
  void upd(int n, int b, int e, int i, int j, pair<ll, ll> v) {
    push(n, b, e);
    // cout << "1a\n";
    if (j < b || e < i)
      return;
    // cout << "2a\n";
    if (i <= b && e <= j) {
      lazy[n] = v; // set lazy
      push(n, b, e);
      return;
    }
    // cout << "3a\n";
    int mid = (b + e) >> 1;
    upd(lc, b, mid, i, j, v);
    upd(rc, mid + 1, e, i, j, v);
    // cout << "4a\n";
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
  for (int i = 0; i < n; i++)
    cin >> a[i];
  segment_tree st;
  st.build(1, 0, n - 1);
  // for (int i = 1; i < 8; i++) {
  //   cout << t[i] << " ";
  // }
  // cout << '\n';
  // for (int i = 1; i < 8; i++) {
  //   cout << lazy[i].first << " ";
  // }
  // cout << '\n';
  // for (int i = 1; i < 8; i++) {
  //   cout << lazy[i].second << " ";
  // }
  // cout << '\n';
  //
  // cout << "done\n";
  while (q--) {
    int type;
    cin >> type;
    if (type == 0) {
      int l, r;
      ll x, y;
      // cout << "reading  " << q << '\n';
      cin >> l >> r >> x >> y;
      // cout << "updating  " << q << '\n';
      st.upd(1, 0, n - 1, l, r - 1, {x, y});
      // cout << "updated  " << q << '\n';
    } else {
      int l, r;
      cin >> l >> r;
      cout << st.query(1, 0, n - 1, l, r - 1) << '\n';
      // cout << "queried  " << q << '\n';
    }
    // for (int i = 1; i < 8; i++) {
    //   cout << t[i] << " ";
    // }
    // cout << '\n';
    // for (int i = 1; i < 8; i++) {
    //   cout << lazy[i].first << " ";
    // }
    // cout << '\n';
    // for (int i = 1; i < 8; i++) {
    //   cout << lazy[i].second << " ";
    // }
    // cout << '\n';
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;

  // cin >> t;
  t = 1;
  while (t--)
    solve();
#ifdef ONPC
  cerr << endl
       << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif
}
