#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
ll const N = 1e5 + 1;
vector<vector<pair<ll, ll>>> tree(4 * N, vector<pair<ll, ll>>(42));
ll t[4 * N];
int arr[N];
void build(int v, int tl, int tr) {
  if (tl == tr) {
    t[v] = 0;
    tree[v][arr[tl]] = {1, 0};
    for (int i = 41 - 1; i >= 0; i--) {
      tree[v][i].second = tree[v][i + 1].second + tree[v][i].first;
    }
    return;
  }
  ll tm = (tl + tr) / 2;
  build(2 * v, tl, tm);
  build(2 * v + 1, tm + 1, tr);
  t[v] = t[2 * v] + t[2 * v + 1];
  for (int i = 1; i < 41; i++) {
    if (tree[2 * v + 1][i].first == 0)
      continue;
    t[v] += tree[2 * v + 1][i].first * tree[2 * v][i + 1].second;
  }
  for (int i = 0; i < 41; i++) {
    tree[v][i].first = tree[2 * v][i].first + tree[2 * v + 1][i].first;
  }
  for (int i = 41 - 1; i >= 0; i--) {
    tree[v][i].second = tree[v][i + 1].second + tree[v][i].first;
  }
}
void update(int v, int tl, int tr, int pos, int val) {
  if (tl == tr) {
    t[v] = 0;
    tree[v][arr[pos]] = {0, 0};
    tree[v][val] = {1, 0};
    arr[pos] = val;
    for (int i = 41 - 1; i >= 0; i--) {
      tree[v][i].second = tree[v][i + 1].second + tree[v][i].first;
    }
    return;
  }
  ll tm = (tl + tr) / 2;
  if (pos <= tm)
    update(2 * v, tl, tm, pos, val);
  else
    update(2 * v + 1, tm + 1, tr, pos, val);
  t[v] = t[2 * v] + t[2 * v + 1];
  for (int i = 1; i < 41; i++) {
    if (tree[2 * v + 1][i].first == 0)
      continue;
    t[v] += tree[2 * v + 1][i].first * tree[2 * v][i + 1].second;
  }
  for (int i = 0; i < 41; i++) {
    tree[v][i].first = tree[2 * v][i].first + tree[2 * v + 1][i].first;
  }
  for (int i = 41 - 1; i >= 0; i--) {
    tree[v][i].second = tree[v][i + 1].second + tree[v][i].first;
  }
}
pair<ll, vector<pair<ll, ll>>> query(int v, int tl, int tr, int l, int r) {
  vector<pair<ll, ll>> tmp(42, {0, 0});
  if (l > r)
    return {0, tmp};
  if (l == tl && r == tr) {
    return {t[v], tree[v]};
  }
  ll tm = (tl + tr) / 2;
  ll ans = 0;
  auto left = query(2 * v, tl, tm, l, min((ll)r, tm));
  auto right = query(2 * v + 1, tm + 1, tr, max((ll)l, tm + 1), r);
  ans += left.first + right.first;
  for (int i = 1; i < 41; i++) {
    if (right.second[i].first == 0)
      continue;
    ans += right.second[i].first * left.second[i + 1].second;
  }
  for (int i = 0; i < 42; i++) {
    tmp[i].first = left.second[i].first + right.second[i].first;
  }
  for (int i = 41 - 1; i >= 0; i--) {
    tmp[i].second = tmp[i + 1].second + tmp[i].first;
  }
  // cout << ans << " " << l << " " << r << "\n";
  // for (int i = 1; i < 8; i++) {
  //   cout << tmp[i].first << " ";
  // }
  // cout << "\n";
  return {ans, tmp};
}
void solve() {
  ll n, q;
  cin >> n >> q;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  build(1, 0, n - 1);
  while (q--) {
    ll x;
    cin >> x;
    if (x == 1) {
      ll l, r;
      cin >> l >> r;
      cout << query(1, 0, n - 1, l - 1, r - 1).first << endl;
    } else {
      ll pos, val;
      cin >> pos >> val;
      update(1, 0, n - 1, pos - 1, val);
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
