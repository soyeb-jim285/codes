#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
ll const N = 1e5 + 9;
ll tree[4 * N];
ll arr[N];
ll const INF = 1e9 + 10;
void build(ll v, ll l, ll r) {
  if (l == r) {
    tree[v] = arr[l];
    return;
  }
  ll m = (l + r) / 2;
  build(2 * v, l, m);
  build(2 * v + 1, m + 1, r);
  tree[v] = min(tree[2 * v], tree[2 * v + 1]);
}
void update(ll v, ll l, ll r, ll pos, ll val) {
  if (l == r) {
    tree[v] = val;
    return;
  }
  ll m = (l + r) / 2;
  if (pos <= m)
    update(2 * v, l, m, pos, val);
  else
    update(2 * v + 1, m + 1, r, pos, val);
  tree[v] = min(tree[2 * v], tree[2 * v + 1]);
}
ll mn(ll v, ll tl, ll tr, ll l, ll r) {
  if (l > r)
    return INF;
  if (l == tl && r == tr) {
    return tree[v];
  }
  ll tm = (tl + tr) / 2;
  return min(mn(v * 2, tl, tm, l, min(r, tm)),
             mn(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r));
}
void solve() {
  ll n, q;
  cin >> n >> q;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  build(1, 0, n - 1);
  // for (int i = 0; i < 4 * n; i++) {
  //   cout << tree[i] << " ";
  // }
  // cout << "\n";
  while (q--) {
    ll x;
    cin >> x;
    if (x == 1) {
      ll k, val;
      cin >> k >> val;
      update(1, 0, n - 1, k - 1, val);
    } else {
      ll l, r;
      cin >> l >> r;
      cout << mn(1, 0, n - 1, l - 1, r - 1) << "\n";
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
