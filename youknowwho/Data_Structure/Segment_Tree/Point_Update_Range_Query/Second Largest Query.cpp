#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
ll const N = 2e5 + 5;
vector<pair<pair<ll, ll>, pair<ll, ll>>> tree(4 * N);
ll arr[N];
void build(int v, int tl, int tr) {
  if (tl == tr) {
    tree[v] = {{arr[tl], 1}, {0, 0}};
    return;
  }
  ll tm = (tl + tr) / 2;
  build(2 * v, tl, tm);
  build(2 * v + 1, tm + 1, tr);
  vector<pair<ll, ll>> tmp = {tree[2 * v].first, tree[2 * v].second,
                              tree[2 * v + 1].first, tree[2 * v + 1].second};
  sort(tmp.begin(), tmp.end(), greater<pair<ll, ll>>());
  tree[v].first = {tmp[0].first, 0};
  for (int i = 0; i < 4; i++) {
    if (tmp[i].first != tree[v].first.first) {
      tree[v].second = {tmp[i].first, 0};
      break;
    }
  }
  for (int i = 0; i < 4; i++) {
    if (tmp[i].first == tree[v].first.first)
      tree[v].first.second += tmp[i].second;
    if (tmp[i].first == tree[v].second.first)
      tree[v].second.second += tmp[i].second;
  }
}
void update(int v, int tl, int tr, int pos, int val) {
  if (tl == tr) {
    tree[v] = {{val, 1}, {0, 0}};
    return;
  }
  ll tm = (tl + tr) / 2;
  if (pos <= tm)
    update(2 * v, tl, tm, pos, val);
  else
    update(2 * v + 1, tm + 1, tr, pos, val);
  vector<pair<ll, ll>> tmp = {tree[2 * v].first, tree[2 * v].second,
                              tree[2 * v + 1].first, tree[2 * v + 1].second};
  sort(tmp.begin(), tmp.end(), greater<pair<ll, ll>>());
  tree[v].first = {tmp[0].first, 0};
  for (int i = 0; i < 4; i++) {
    if (tmp[i].first != tree[v].first.first) {
      tree[v].second = {tmp[i].first, 0};
      break;
    }
  }
  for (int i = 0; i < 4; i++) {
    if (tmp[i].first == tree[v].first.first)
      tree[v].first.second += tmp[i].second;
    if (tmp[i].first == tree[v].second.first)
      tree[v].second.second += tmp[i].second;
  }
}
pair<pair<ll, ll>, pair<ll, ll>> query(int v, int tl, int tr, int l, int r) {
  if (l > r)
    return {{0, 0}, {0, 0}};
  if (l == tl && r == tr)
    return tree[v];
  ll tm = (tl + tr) / 2;
  pair<pair<ll, ll>, pair<ll, ll>> left =
      query(2 * v, tl, tm, l, min((ll)r, tm));
  pair<pair<ll, ll>, pair<ll, ll>> right =
      query(2 * v + 1, tm + 1, tr, max((ll)l, tm + 1), r);
  vector<pair<ll, ll>> tmp = {left.first, left.second, right.first,
                              right.second};
  sort(tmp.begin(), tmp.end(), greater<pair<ll, ll>>());
  pair<pair<ll, ll>, pair<ll, ll>> res;
  res.first = {tmp[0].first, 0};
  for (int i = 0; i < 4; i++) {
    if (tmp[i].first != res.first.first) {
      res.second = {tmp[i].first, 0};
      break;
    }
  }
  for (int i = 0; i < 4; i++) {
    if (tmp[i].first == res.first.first)
      res.first.second += tmp[i].second;
    if (tmp[i].first == res.second.first)
      res.second.second += tmp[i].second;
  }
  return res;
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
      ll pos, val;
      cin >> pos >> val;
      pos--;
      update(1, 0, n - 1, pos, val);
    } else {
      ll l, r;
      cin >> l >> r;
      l--, r--;
      auto as = query(1, 0, n - 1, l, r);
      cout << as.second.second << "\n";
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
