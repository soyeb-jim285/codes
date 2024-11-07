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
void solve() {
  ll n, q;
  cin >> n >> q;
  for (int i = 0; i < n; i++) {
    cin >> arr[i].first;
    arr[i].second = 1;
  }
  build(1, 0, n - 1);
  while (q--) {
    ll x;
    cin >> x;
    if (x == 1) {
      ll k, val;
      cin >> k >> val;
      update(1, 0, n - 1, k, {val, 1});
    } else {
      ll l, r;
      cin >> l >> r;
      cout << mn(1, 0, n - 1, l, r - 1).first << " "
           << mn(1, 0, n - 1, l, r - 1).second << "\n";
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
