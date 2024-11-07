#include <bits/stdc++.h>
using namespace std;
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
      return -2e9;
    int j = log[R - L + 1];
    return fn(st[L][j], st[R - (1 << j) + 1][j]);
  }
};
void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  map<int, int> cnt;
  for (int &i : a)
    cin >> i;
  SparseTable<int> st(n);
  st.build(a);
  for (int i = 0; i < n; i++) {
    int low = i, high = n - 1;
    int g = a[i];
    while (low <= high) {
      int mid = (low + high) / 2;
      if (st.query(i, mid) == g) {
        low = mid + 1;
      } else {
        high = mid - 1;
      }
    }
    cnt[g] += low - i;
    i = low;
  }
  int q;
  cin >> q;
  while (q--) {
    ll x;
    cin >> x;
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
