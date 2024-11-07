#include <bits/stdc++.h>
using namespace std;

#define sz(a) ((int)((a).size()))

typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
template <typename T> struct SparseTable {
  vector<vector<T>> st;
  vector<int> log;
  SparseTable(int n) {
    int maxLog = log2(n) + 1;
    st.assign(n, vector<T>(maxLog));
    log.assign(n + 1, 0);
    for (int i = 2; i <= n; i++) {
      log[i] = log[i / 2] + 1;
    }
  }
  void build(vector<T> &arr) {
    int n = arr.size();
    int maxLog = log2(n) + 1;
    for (int i = 0; i < n; i++) {
      st[i][0] = arr[i];
    }
    for (int j = 1; (1 << j) <= n; j++) {
      for (int i = 0; i + (1 << j) <= n; i++) {
        st[i][j] = fn(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
      }
    }
  }
  inline T fn(T a, T b) { return __gcd(a, b); }
  inline T query(int L, int R) {
    if (R < L)
      return 0;
    int j = log[R - L + 1];
    return fn(st[L][j], st[R - (1 << j) + 1][j]);
  }
};
void solve() {
  ll n, k;
  cin >> n >> k;
  ll g = 0, mx_g = 0;
  vector<ll> a(n), b(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    b[i] = a[i] + k;
    g = __gcd(g, a[i]);
    mx_g = __gcd(mx_g, b[i]);
  }
  // cout << g << " " << mx_g << '\n';
  mx_g = max(mx_g, g);
  SparseTable<ll> st(n);
  SparseTable<ll> st2(n);
  // for (auto ic : a)
  //   cout << ic << " ";
  // cout << '\n';
  // for (int i = 0; i < n; i++) {
  //   cout << b[i] << " ";
  // }
  // cout << "\n";
  st.build(a);
  st2.build(b);
  vector<ll> pref(n);
  for (int i = 0; i < n; i++) {
    pref[i] = a[i];
    if (i > 0)
      pref[i] = __gcd(pref[i], pref[i - 1]);
  }
  for (int i = 0; i < n; i++) {
    ll gg = __gcd(st.query(i + 1, n - 1), st2.query(0, i));
    // cout << i << " " << gg << " " << st2.query(i + 1, n - 1) << " "
    //      << st.query(0, i) << '\n';

    mx_g = max(mx_g, gg);
  }
  for (int i = 0; i < n - 1; i++) {
    if (pref[i] != pref[i + 1]) {
      for (int j = i; j < n; j++) {
        ll gg = __gcd(pref[i], st.query(j + 1, n - 1));
        // cout << i << " " << j << " " << n - 1 << " " << gg << " "
        //      << st.query(j + 1, n - 1) << '\n';
        gg = __gcd(gg, st2.query(i + 1, j));
        // cout << i << " " << j << " " << gg << " " << st2.query(i + 1, j)
        //      << "--\n";
        mx_g = max(mx_g, gg);
      }
      // cout << i << " " << mx_g << '\n';
    }
  }
  cout << mx_g << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--)
    solve();
#ifdef ONPC
  cerr << endl
       << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif
}
