#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
ll const N = 1e5 + 9;
ll tree[4 * N];
int indx[4 * N];
ll arr[N];
void build(ll v, ll l, ll r) {
  if (l == r) {
    tree[v] = arr[l];
    indx[v] = l + 1;
    return;
  }
  ll m = (l + r) / 2;
  build(2 * v, l, m);
  build(2 * v + 1, m + 1, r);
  tree[v] = tree[2 * v] + tree[2 * v + 1];
}
void update(ll v, ll l, ll r, ll pos) {
  if (l == r) {
    tree[v] ^= 1;
    return;
  }
  ll m = (l + r) / 2;
  if (pos <= m)
    update(2 * v, l, m, pos);
  else
    update(2 * v + 1, m + 1, r, pos);
  tree[v] = tree[2 * v] + tree[2 * v + 1];
}
ll onee(ll v, ll tl, ll tr, ll k) {
  if (tl == tr) {
    return tl + 1;
  }
  ll tm = (tl + tr) / 2;
  ll ans;
  if (tree[v] >= k) {
    if (tree[2 * v] >= k) {
      ans = onee(2 * v, tl, tm, k);
    } else {
      ans = onee(2 * v + 1, tm + 1, tr, k - tree[2 * v]);
    }
  } else {
    return -1;
  }
  return ans;
}
void solve() {
  int n, q;
  cin >> n >> q;
  string s;
  cin >> s;
  for (int i = 0; i < n; i++) {
    arr[i] = s[i] - '0';
  }
  build(1, 0, n - 1);
  while (q--) {
    int type;
    cin >> type;
    if (type == 1) {
      int pos;
      cin >> pos;
      update(1, 0, n - 1, pos - 1);
    } else {
      int k;
      cin >> k;
      cout << onee(1, 0, n - 1, k) << "\n";
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
