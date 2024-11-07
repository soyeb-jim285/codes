#include <bits/stdc++.h>
using namespace std;

#define int long long int

template <typename T, class F = function<T(const T &, const T &)>>
class SparseTable {
public:
  int n;
  vector<vector<T>> mat;
  F func;

  SparseTable(const vector<T> &a, const F &f) : func(f) {
    n = static_cast<int>(a.size());
    int max_log = 32 - __builtin_clz(n);
    mat.resize(max_log);
    mat[0] = a;
    for (int j = 1; j < max_log; j++) {
      mat[j].resize(n - (1 << j) + 1);
      for (int i = 0; i <= n - (1 << j); i++) {
        mat[j][i] = func(mat[j - 1][i], mat[j - 1][i + (1 << (j - 1))]);
      }
    }
  }

  T get(int from, int to) const {
    assert(0 <= from && from <= to && to <= n - 1);
    int lg = 32 - __builtin_clz(to - from + 1) - 1;
    return func(mat[lg][from], mat[lg][to - (1 << lg) + 1]);
  }
};
// SparseTable<long long> mn(v, [&](long long i, long long j) { return min(i,
// j); });

void test_case() {

  int n, k;
  cin >> n >> k;
  vector<int> a(n), b(n);
  int can = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    b[i] = a[i] + k;
    can = __gcd(can, b[i]);
  }

  SparseTable<long long> mn(
      b, [&](long long i, long long j) { return __gcd(i, j); });
  vector<int> suffix(n);
  suffix[n - 1] = a[n - 1];
  for (int i = n - 2; i >= 0; i--) {
    suffix[i] = __gcd(suffix[i + 1], a[i]);
  }
  map<int, int> prefix;
  int ans = max(can, suffix[0]), g = 0;
  for (int i = 0; i < n; i++) {

    for (auto [gc, l] : prefix) {

      int cur = mn.get(l + 1, i);
      int suf = 0;
      if (i + 1 < n)
        suf = suffix[i + 1];
      int curans = __gcd(gc, cur);
      curans = __gcd(curans, suf);
      //   cout << i << ' ' << l << ' ' << gc << '\n';
      ans = max(curans, ans);
    }
    int curans = mn.get(0, i);
    int suf = 0;
    if (i + 1 < n)
      suf = suffix[i + 1];
    curans = __gcd(curans, suf);
    ans = max(ans, curans);
    g = __gcd(g, a[i]);
    prefix[g] = i;
  }

  cout << ans << '\n';
}

int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t = 1;
  cin >> t;

  for (int cs = 1; cs <= t; cs++) {
    // cout << "Case " << cs << ": ";
    test_case();
  }

  return 0;
}
