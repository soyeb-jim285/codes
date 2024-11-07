#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
ll const N = 1e5 + 9;
vector<pair<ll, ll>> tree(4 * N);
vector<pair<ll, ll>> arr(N);
void build(ll v, ll l, ll r) {
  if (l == r) {
    tree[v] = arr[l];
    return;
  }
  ll m = (l + r) / 2;
  build(2 * v, l, m);
  build(2 * v + 1, m + 1, r);
  tree[v].first = min(tree[2 * v].first, tree[2 * v + 1].first);
  tree[v].second = 0;
  if (tree[v].first == tree[2 * v].first) {
    tree[v].second += tree[2 * v].second;
  }
  if (tree[v].first == tree[2 * v + 1].first) {
    tree[v].second += tree[2 * v + 1].second;
  }
}
void update(ll v, ll l, ll r, ll pos, pair<ll, ll> val) {
  if (l == r) {
    tree[v] = val;
    return;
  }
  ll m = (l + r) / 2;
  if (pos <= m)
    update(2 * v, l, m, pos, val);
  else
    update(2 * v + 1, m + 1, r, pos, val);
  tree[v].first = min(tree[2 * v].first, tree[2 * v + 1].first);
  tree[v].second = 0;
  if (tree[v].first == tree[2 * v].first) {
    tree[v].second += tree[2 * v].second;
  }
  if (tree[v].first == tree[2 * v + 1].first) {
    tree[v].second += tree[2 * v + 1].second;
  }
}
pair<ll, ll> mn(ll v, ll tl, ll tr, ll l, ll r) {
  if (l > r)
    return {1e10, 0};
  if (l == tl && r == tr) {
    return tree[v];
  }
  ll tm = (tl + tr) / 2;
  pair<ll, ll> left = mn(v * 2, tl, tm, l, min(r, tm));
  pair<ll, ll> right = mn(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
  pair<ll, ll> res;
  res.first = min(left.first, right.first);
  res.second = 0;
  if (res.first == left.first) {
    res.second += left.second;
  }
  if (res.first == right.first) {
    res.second += right.second;
  }
  return res;
}
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
  ll n;
  cin >> n;
  vector<ll> a(n);
  for (ll i = 0; i < n; i++) {
    cin >> a[i];
    arr[i] = {a[i], 1};
  }
  build(1, 0, n - 1);
  SparseTable<ll> st(n);
  ll q;
  cin >> q;
  st.build(a);

  while (q--) {
    ll l, r;
    cin >> l >> r;
    l--, r--;
    ll g = st.query(l, r);
    pair<ll, ll> p = mn(1, 0, n - 1, l, r);
    if (p.first == g) {
      cout << r - l + 1 - p.second << "\n";
    } else {
      cout << r - l + 1 << "\n";
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
